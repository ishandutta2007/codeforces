#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

// TCR ( https://github.com/Laakeri/contestlib/blob/master/src/string/lcparray.cpp )
vector<int> suffixArray(string s) {
	int S = 256;
	int n=s.size();int N=n+S;
	vector<int> sa(n), ra(n);
	for(int i=0;i<n;i++) {sa[i]=i;ra[i]=s[i];}
	for(int k=0;k<n;k?k*=2:k++) {
		vector<int> nsa(sa), nra(n), cnt(N);
		for(int i=0;i<n;i++) nsa[i]=(nsa[i]-k+n)%n;
		for(int i=0;i<n;i++) cnt[ra[i]]++;
		for(int i=1;i<N;i++) cnt[i]+=cnt[i-1];
		for(int i=n-1;i>=0;i--) sa[--cnt[ra[nsa[i]]]]=nsa[i];
		int r=0;
		for(int i=1;i<n;i++) {
			if(ra[sa[i]]!=ra[sa[i-1]]) r++;
			else if(ra[(sa[i]+k)%n]!=ra[(sa[i-1]+k)%n]) r++;
			nra[sa[i]]=r;
		}
		ra=nra;
	}
	return sa;
}

vector<int> lcpArray(string s, vector<int> sa) {
	int n=s.size(), k=0;
	vector<int> ra(n), lcp(n);
	for (int i=0;i<n;i++) ra[sa[i]]=i;
	for (int i=0;i<n;i++) {
		if (k) k--;
		if (ra[i]==n-1) {
			k=0;
			continue;
		}
		int j=sa[ra[i]+1];
		while (k<n&&s[(i+k)%n]==s[(j+k)%n]) k++;
		lcp[ra[i]]=k;
		if (ra[(sa[ra[i]]+1)%n]>ra[(sa[ra[j]]+1)%n]) k=0;
	}
	return lcp;
}

struct Helper {
	ll sum = 0;
	vector<pair<int, int>> vals;

	void add(int v) {
		sum += v;
		vals.push_back({v, 1});
	}
	void cap(int v) {
		int cou = 0;
		while((vals.size() > 0) && (vals.back().first >= v)) {
			int el_cou = vals.back().second;
			sum -= (ll)vals.back().first * el_cou;
			cou += el_cou;
			vals.pop_back();
		}
		sum += (ll)v * cou;
		if (cou) vals.push_back({v, cou});
	}
};

const int N = 1<<18;
const int INF = 1e9 + 7;
int mp[N]; // Map from index in string to suffix array
int lcp_seg[2 * N];

int getMin(int a, int b, int i = 1, int ia = 0, int ib = N-1) {
	if (b < ia || ib < a) return INF;
	if (a <= ia && ib <= b) return lcp_seg[i];
	int mid = (ia + ib) >> 1;
	int lv = getMin(a, b, 2*i, ia, mid);
	int rv = getMin(a, b, 2*i+1, mid+1, ib);
	return min(lv, rv);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, t;
	cin >> n >> t;

	string str;
	cin >> str;

	++n;
	str.push_back('$');

	// cout << str << '\n';

	vector<int> sa = suffixArray(str);
	vector<int> lcp = lcpArray(str, sa);
	for (int i = 0; i < n; ++i) mp[sa[i]] = i;

	/*
	cout << str << '\n';
	for (auto it : sa) cout << it << ' '; cout << '\n';
	for (auto it : lcp) cout << it << ' '; cout << '\n';
	*/

	for (int i = 0; i < n; ++i) lcp_seg[i+N] = lcp[i];
	for (int i = N-1; i > 0; --i) lcp_seg[i] = min(lcp_seg[2*i], lcp_seg[2*i+1]);

	for (int q = 0; q < t; ++q) {
		int an, bn;
		cin >> an >> bn;
		vector<int> as(an);
		vector<int> bs(bn);
		for (int i = 0; i < an; ++i) {
			cin >> as[i];
			as[i] = mp[as[i] - 1];
		}
		for (int i = 0; i < bn; ++i) {
			cin >> bs[i];
			bs[i] = mp[bs[i] - 1];
		}
		sort(as.begin(), as.end());
		sort(bs.begin(), bs.end());
	
		/*	
		for (auto it : as) cout << it << ' '; cout << '\n';
		for (auto it : bs) cout << it << ' '; cout << '\n';
		*/

		ll ans = 0;
		Helper h;
		int j;

		// Pairs where bs <= as
		h.sum = 0;
		h.vals.clear();
		j = 0;
		for (int i = 0; i < an; ++i) {
			while((j < bn) && (bs[j] <= as[i])) {
				int len = n-1 - sa[bs[j]];
				int mn = getMin(bs[j], as[i] - 1);
				// cout << "activate " << j << ": " << bs[j] << ' ' << sa[bs[j]] << " -> " << len << ' ' << mn << '\n';
				h.add(min(len, mn)); // Possible problem?
				++j;
			}

			ans += h.sum;
			// cout << h.sum << '\n';

			if (i+1 < an) {
				int mn = getMin(as[i], as[i+1]-1);
				h.cap(mn);
			}
		}

		// Pairs where as < bs
		h.sum = 0;
		h.vals.clear();
		j = bn - 1;
		for (int i = an-1; i >= 0; --i) {
			while((j >= 0) && (as[i] < bs[j])) {
				int mn = getMin(as[i], bs[j] - 1);
				h.add(mn);
				--j;
			}

			ans += h.sum;
			// cout << h.sum << '\n';

			if (i-1 >= 0) {
				int mn = getMin(as[i-1], as[i]-1);
				h.cap(mn);
			}
		}

		cout << ans << '\n';
	}
}