#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define SET(p,k) memset(p, k, sizeof(p));
#define MOD(n,k) ((((n) % (k)) + (k)) % (k))
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	string s;
	ll res = 0;

	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'Q') {
			for (int j = i; j < s.size(); j++) {
				if (s[j] == 'A') {
					for (int l = j; l < s.size(); l++) {
						if (s[l] == 'Q') {
							res++;
						}
					}
				}
			}
		}
	}

	cout << res << endl;

	return 0;
}