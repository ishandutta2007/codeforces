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
#define setBit(S, j) (S |= (1 << j ) )
#define LSB(S) (S & (-S))

int main(){
	vector<ll> tran;
	ll n;

	cin >> n;

	for(ll i = 1; i*(i+1)/2 <= 2e9; i++)
		tran.push_back(i*(i+1)/2);

	for(int i = 0; tran[i] < n; i++){
		int x = n - tran[i];
		int a = 0, b = tran.size() - 1, mit = (a+b)/2;
		
		if ( *(lower_bound(tran.begin(), tran.end(), x)) == x){
            cout << "YES";
            return 0;
		}
	}

	cout << "NO";
	return 0;
}