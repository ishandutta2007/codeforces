
// Problem : B. Omkar and Heavenly Tree
// Contest : Codeforces - Codeforces Round #749 (Div. 1 + Div. 2, based on Technocup 2022 Elimination Round 1)
// URL : https://codeforces.com/contest/1586/problem/B
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = int(a); i <= int(b); i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 100005;
int n, m, ex[MX];

void main_() {
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++)
		ex[i] = 0;
	
	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		ex[b] = 1;
	}
	
	for (int i = 1; i <= n; i++)
		if (!ex[i]) {
			for (int j = 1; j <= n; j++)
				if (i != j)
					cout << i << " " << j << endl;
			return;
		}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}