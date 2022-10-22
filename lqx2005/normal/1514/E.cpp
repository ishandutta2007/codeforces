#include <bits/stdc++.h>

#define sz(a) int((a).size())
using namespace std;
mt19937 rnd(time(NULL) ^ *new char);
const int N = 100 + 10;
int t, n;
int v[N], top = 0;
int e[N][N];
vector<int> stk[N];
int dire(int a, int b) {
	cout << "1 " << a - 1 <<" " << b - 1 << endl;
	int res;
	cin >> res;
	return res;
}

int exist(int x, vector<int> s) {
	if(sz(s) == 0) return 0;
	cout << "2 " << x - 1 <<" " << sz(s) <<" ";
	for(int i = 0; i < sz(s); i++) {
		cout << s[i] - 1 <<" ";
	}
	cout << endl;
	int res;
	cin >> res;
	return res;
}


void divide(vector<int> p) {
	if(sz(p) <= 0) return;
	shuffle(p.begin(), p.end(), rnd);
	int x = p[0];
	vector<int> L, R;
	for(int i = 1; i < sz(p); i++) {
		if(dire(x, p[i])) R.push_back(p[i]);
		else L.push_back(p[i]);
	}
	divide(L), v[++top] = x, divide(R);
	return;
}

void solve() {
	top = 0;
	cin >> n;
	vector<int> id(n);
	for(int i = 0; i < n; i++) id[i] = i + 1;
	divide(id);
	top = 0;
	for(int i = 1; i <= n; i++) {
		int x = v[i], len = top;
		for(; top; top--) {
			vector<int> nex;
			for(int j = top; j >= 1; j--) {
				nex.insert(nex.end(), stk[j].begin(), stk[j].end());
			}
			if(!exist(x, nex)) break;
		}
		vector<int> now;
		now.push_back(x);
		for(int j = top + 1; j <= len; j++) {
			now.insert(now.end(), stk[j].begin(), stk[j].end());
			stk[j].clear();
		}
		stk[++top] = now;
	}
	memset(e, 0, sizeof(e));
	for(int a = 1; a <= top; a++) {
		for(int b = a; b <= top; b++) {
			for(int j = 0; j < sz(stk[a]); j++) {
				for(int k = 0; k < sz(stk[b]); k++) {
					e[stk[a][j]][stk[b][k]] = 1;
				}
			}
		}
	}
	cout << 3 << endl;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			cout << e[i][j];
		}
		cout << endl;
	}
	int num;
	cin >> num;
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	for(cin >> t; t--; solve());
	return 0;
}