#include <iostream>
#include <vector>
#include <utility>
using namespace std;
typedef long long ll;

int ask(const vector<int>& nodes) {
	if (nodes.size() <= 1) return 0;
	cout << "? " << nodes.size() << endl;
	for (auto it : nodes) cout << (it + 1) << ' ';
	cout << endl;

	int ans;
	cin >> ans;
	return ans;
}

void rem(vector<int>& a, int b) {
	int rems = 0;
	int j = 0;
	for (int i = 0; i + rems < a.size(); ++i) {
		swap(a[i], a[i + rems]);
		if (a[i] == b) {
			++rems;
			--i;
		}
	}
	a.resize((int)a.size() - rems);
}

pair<vector<int>, vector<int>> halve(const vector<int>& vec) {
	int n = vec.size();
	vector<int> a((n+1) / 2);
	vector<int> b(n / 2);
	for (int i = 0; i < a.size(); ++i) a[i] = vec[i];
	for (int i = 0; i < b.size(); ++i) b[i] = vec[a.size() + i];
	return {a, b};
}

// Finds all outgoing edges from i to tars
void find(int i, vector<int> tars, vector<int>& res) {
	int bm = ask(tars);
	tars.push_back(i);
	int m = ask(tars);
	tars.pop_back();

	if (m == bm) return;
	if (tars.size() == 1) {
		res.push_back(tars[0]);
	} else {
		auto pr = halve(tars);
		find(i, pr.first, res);
		find(i, pr.second, res);
	}
}

const int N = 600;
int side[N];
int pre[N];
bool reached[N];

// At most 20 000 queries, 20 000 / 600 = ~33
int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) pre[i] = -1;
	for (int i = 0; i < n; ++i) side[i] = -1;


	vector<int> rest(n);
	for (int i = 0; i < n; ++i) rest[i] = i;
	
	while(rest.size() > 0) {
		int bs = rest.back();
		rest.pop_back();

		vector<int> que;
		side[bs] = 0;
		que.push_back(bs);

		for (int j = 0; j < que.size(); ++j) {

			int i = que[j];
			vector<int> tars;
			find(i, rest, tars);
			for (auto t : tars) {
				rem(rest, t);
				pre[t] = i;
				side[t] = 1 - side[i];
				que.push_back(t);
			}
		}
	}

	vector<int> evens;
	vector<int> odds;
	for (int i = 0; i < n; ++i) {
		if (side[i] == 0) evens.push_back(i);
		else if (side[i] == 1) odds.push_back(i);
	}
	
	int aev = ask(evens);
	int aod = ask(odds);
	if (aev == 0 && aod == 0) {
		cout << "Y " << evens.size() << endl;
		for (auto it : evens) cout << it+1 << ' '; cout << endl;
	} else {


		if (aod > 0) swap(evens, odds);

		// The two conflicting nodes
		int a = -1;
		int b = -1;
		while(! evens.empty()) {
			vector<int> res;
			a = evens.back();
			evens.pop_back();
			find(a, evens, res);
			if (res.size() > 0) {
				b = res[0];
				break;
			}
		}


		int tmp = a;
		while(tmp != -1) {
			reached[tmp] = true;
			tmp = pre[tmp];
		}

		vector<int> ans;
		while(true) {
			ans.push_back(b);
			if (reached[b]) {
				reached[b] = false;
				break;
			}
			b = pre[b];
		}

		vector<int> rev;
		while(reached[a]) {
			rev.push_back(a);
			a = pre[a];
		}

		while(! rev.empty()) {
			ans.push_back(rev.back());
			rev.pop_back();
		}

		cout << "N " << ans.size() << endl;
		for (auto it : ans) cout << it+1 << ' '; cout << endl << '\n';
	}
}