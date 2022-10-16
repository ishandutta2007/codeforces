#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define MP make_pair
#define DB(x) cout << #x << "=" << x << endl

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int maxn = 100100;

int p[maxn];
int mk[maxn];

int dfs(int v, int x1, int x2){
	if (mk[v]) return 0;
	mk[v] = x1;
	return dfs(p[v], x2, x1) + 1;
}

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;

	for (int i = 1; i <= n; ++i){
		cin >> p[i];
	}

	for (int i = 1; i <= n; ++i){
		if (p[i] == i){
			cout << "YES" << endl;
			for (int j = 1; j <= n; ++j){
				if (i == j) continue;
				cout << i << " " << j << endl;
			}
			exit(0);
		}
	}

	for (int i = 1; i <= n; ++i){
		if (p[p[i]] == i){
			for (int j = 1; j <= n; ++j){
				if (j == i || j == p[i] || mk[j]) continue;
				int len = dfs(j, i, p[i]);
				if (len & 1){
					cout << "NO" << endl;
					exit(0);
				}
			}

			cout << "YES" << endl;
			cout << i << " " << p[i] << endl;
			for (int j = 1; j <= n; ++j){
				if (j == i || j == p[i]) continue;
				cout << mk[j] << " " << j << endl;
			}
			exit(0);
		}
	}

	cout << "NO" << endl;
	return 0;
}