#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

int d[10][10];
string s;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> s;
	for (char &c : s)
		c -= '0';

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			int res = 0;

			for (int a = 0; a < 10; a++)
				for (int b = 0; b < 10; b++) {
					int dis[10];
					memset(dis, -1, sizeof(dis));

					queue<int> q;
					q.push(a);

					while (q.size()) {
						int u = q.front();
						int x = dis[u];
						q.pop();

						if (dis[(u + i) % 10] == -1) {
							q.push((u + i) % 10);	
							dis[(u + i) % 10] = x + 1;
						}

						if (dis[(u + j) % 10] == -1) {
							q.push((u + j) % 10);
							dis[(u + j) % 10] = x + 1;
						}
					}

					d[a][b] = dis[b];
				}

			for (int k = 0; k + 1 < s.size(); k++) {
				if (d[s[k]][s[k+1]] == -1) {
					res = -1;
					break;
				} else {
					res += d[s[k]][s[k+1]];
				}
			}

			cout << res << " ";
		}

		cout << endl;
	}

	return 0;
}