#include <bits/stdc++.h>

#define ll long long
#define vi vector<int>
#define vb vector<bool>
#define ii pair<int, int>
#define vii vector<ii>
#define fi first
#define se second
#define endl '\n'

#define isOn(S, j) (S & (1 << j) )
#define setBit(S, j) (S |= (1 << j ) )
#define LSB(S) (S & (-S))

using namespace std;

#define M 1000000007

ll pot2[(ll)1e6+2];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);

	pot2[0] = 0;
	ll pot = 1;
	for(ll i = 1; i <= 1e6; i++){
		pot2[i] = (pot2[i-1] + pot) % M;
		pot = (pot*(ll)2) % M;
	}

	string s; cin >> s;
	bool f = false;
	ll a = 0, b = 0, res = 0, aux = 0;;
	for(int i = 0; i < s.size(); ){
		if ( !f ){
			if ( s[i] == 'a' )
				a++;
			else{
				f = !f;
				b++;
			}
			i++;
		}else{
			if ( s[i] == 'b' ){
				b++;
				i++;
			}
			else{
				f = !f;
				res += (b * pot2[a]) % M;
				res %= M;
				b = 0;
			}
		}
	}

	res += (b * pot2[a]) % M;

	cout << res % M;

	return 0;
}