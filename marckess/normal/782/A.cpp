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

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, x, mx=0, c=0;
	bitset<100005> bs;
	cin >> n;
	for(int i = 0; i < n*2; i++){
		cin >> x;
		if ( bs[x] )
			c--;
		else{
			c++;
			bs[x] = 1;
		}
		mx = max(mx, c);
	}

	cout << mx;

	return 0;
}