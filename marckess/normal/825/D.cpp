#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;
typedef vector<ii> vii;

#define fi first
#define se second
#define endl '\n'
#define MOD(n,k) ( (n % k) + k ) % k
#define isOn(S, j) (S & (1 << j) )
#define setBit(S, j) (S | (1 << j ) )
#define LSB(S) (S & (-S))

int n = 'z' - 'a' + 1;
string s, t;
vi cub(n), nec(n);

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> s >> t;

	//Contar
	for (char c : s)
		if (c != '?')
			cub[c-'a']++;
	for (char c : t)
		nec[c-'a']++;

	//Obtener respuesta
	int j = 0, suit = 1;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '?') {
			while ( !nec[j] || nec[j] * suit <= cub[j] ) {
				if (j == n-1) {
					j = 0;
					suit++;
				} else {
					j++;
				}
			}
			s[i] = j + 'a';
			cub[j]++;
		}
	}

	cout << s << endl;

	return 0;
}