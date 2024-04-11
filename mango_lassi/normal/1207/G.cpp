#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

pair<vector<int>, vector<int>> suffixArray(const string& str, int mx = 256) {
	int n = str.size();
	vector<int> sa(n), rev(n), nsa(n), nrev(n), cou(n+mx+1);
	for (int i = 0; i < n; ++i) sa[i] = i;
	for (int i = 0; i < n; ++i) rev[i] = str[i];
	for (int s = 0; s < n; s = (s?2*s:s+1), rev = nrev) {
		for (int i = 0; i < n; ++i) nsa[i] = (sa[i]-s + n*(sa[i] < s));
		for (auto& c : cou) c = 0;
		for (auto  v : rev) ++cou[v + 1];
		for (int j = 1; j <= n+mx; ++j) cou[j] += cou[j-1];
		for (auto i : nsa) {
			sa[cou[rev[i]]] = i;
			++cou[rev[i]];
		}
		for (int r = 0, j = 0; j < n; ++j) {
			r += (j && (rev[sa[j]] != rev[sa[j-1]]
				|| (rev[(sa[j]+s)%n] != rev[(sa[j-1]+s)%n])));
			nrev[sa[j]] = r;
		}
	}
	return {sa, rev};
}
int compare(int i, const string& a, const string& b) {
	for (int j = 0; j < b.size(); ++j) {
		if (i+j >= a.size()) return -1;
		if (a[i+j] != b[j]) return (a[i+j] < b[j] ? -1 : 1);
	}
	return 0;
}
int countOccs(const vector<int>& sa, const string& str, const string& pat) {
	// Find first s.t. compare(sa[j], str, pat) >= 0
	int low1 = 0;
	int high1 = sa.size();
	while(low1 != high1) {
		int mid = (low1 + high1) >> 1;
		if (compare(sa[mid], str, pat) == -1) low1 = mid + 1;
		else high1 = mid;
	}
	// Find last s.t. compare(sa[j], str, pat) <= 0
	int low2 = -1;
	int high2 = (int)sa.size() - 1;
	while(low2 != high2) {
		int mid = (low2 + high2 + 1) >> 1;
		if (compare(sa[mid], str, pat) == 1) high2 = mid - 1;
		else low2 = mid;
	}
	return low2 - low1 + 1;
}
void kmpSub(const string& str, const string& pat, vector<int>& aux, vector<int>& res, bool phase) {
	int c = (phase ? -1 : str[0] == pat[0]); // current value
	res[0] = c;
	for (int i = 1; i < res.size(); ++i) {
		char t = str[i - phase]; // extending char
		while((c > -1) && (pat[c] != t)) c = aux[c];
		res[i] = ++c;
		if (c == pat.size()) c = aux[c]; // full match
	}
}

// Knuth-morris-pratt pattern matching
vector<int> kmp(const string& str, const string& pat) {
	vector<int> aux(pat.size()+1); // aux[i] := max_j : pat[0..j) = pat[i-j..i), and j < i
	vector<int> res(str.size());   // res[i] := max_j : pat[0..j) = str(i-j..i], and j <= i+1
	kmpSub(pat, pat, aux, aux, 1); // Create aux array for prefix function
	kmpSub(str, pat, aux, res, 0); // Find result. Can match with multiple strings here
	return res;
}

const int N = 4 * (int)1e5;
const int Q = 4 * (int)1e5;

vector<int> conns[N];
char c_add[N];
int par[N];
int siz[N];
bool used[N];

vector<int> q_ind[N];
string queries[Q];
int ans[Q];

void recAnswer(int i, const vector<int>& sa, const string& str, string& path) {
	// Answer queries in this node
	for (auto qi : q_ind[i]) {
		const string& pat = queries[qi];

		int n = (int)str.size() - 1;
		int m = pat.size();
		if (n >= m) {
			int occs = countOccs(sa, str, pat);
			ans[qi] += occs;
			// if (qi == 2) cerr << "add " << occs << " occs to " << qi << " (" << pat << ") from " << str << endl;
		}
		
		int ai = max(0, n-(m-1));
		int bi = min(n+(m-1), (int)path.size());
		int len = bi - ai;
		if (len >= m) {
			string subpath(len, '_');
			for (int j = 0; j < len; ++j) subpath[j] = path[ai + j];

			vector<int> matches = kmp(subpath, pat);
			int match_cou = 0;
			for (int j = 0; j < len; ++j) {
				if (matches[j] == m) ++match_cou;
			}
			ans[qi] += match_cou;
			// if (qi == 2) cerr << "add " << match_cou << " occs to " << qi << " (" << pat << ") from " << subpath << endl;
		}
	}

	// Recursively answer queries
	for (auto t : conns[i]) {
		if (used[t]) continue;
		path.push_back(c_add[t]);
		recAnswer(t, sa, str, path);
		path.pop_back();
	}
}

void handle(int i, int p) {
	// Find string corresponding to path [p, i]
	string str;
	int j = i;
	for (int j = i;; j = par[j]) {
		str.push_back(c_add[j]);
		if (j == p) break;
	}
	reverse(str.begin(), str.end());
	str.push_back('#');

	int n = str.size();
	vector<int> sa = suffixArray(str).first;

	// Recursively answer queries
	string path = str;
	path.pop_back();
	recAnswer(i, sa, str, path);
}

int calcSiz(int i) {
	siz[i] = 1;
	for (auto t : conns[i]) {
		if (! used[t]) siz[i] += calcSiz(t);
	}
	return siz[i];
}

bool solve(int i, int p = -1, int n = -1) {
	if (n == -1) {
		n = calcSiz(i);
		p = i;
	}
	bool found = false;
	for (auto t : conns[i]) {
		if (! used[t]) found |= solve(t, p, n);
	}
	if ((! found) && (2*siz[i] >= n)) {
		handle(i, p);
		found = true;
		used[i] = true;
		for (auto t : conns[i]) {
			while (! used[t]) solve(t);
		}
	}
	return found;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int t;
		cin >> t;
		if (t == 1) {
			par[i] = i;
		} else {
			cin >> par[i];
			--par[i];
			conns[par[i]].push_back(i);
		}
		cin >> c_add[i];
	}
	
	int q;
	cin >> q;
	for (int qi = 0; qi < q; ++qi) {
		int i;
		cin >> i >> queries[qi];
		q_ind[i-1].push_back(qi);
	}
	for (int i = 0; i < n; ++i) {
		if (par[i] == i) {
			while(! used[i]) solve(i);
		}
	}
	for (int qi = 0; qi < q; ++qi) cout << ans[qi] << '\n';
}