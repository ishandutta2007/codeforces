#include <bits/stdc++.h>

#define ll long long
#define vi vector<int>
#define vb vector<bool>
#define ii pair<int, int>
#define II pair<ll,ll>
#define vii vector<ii>
#define vII vector<II>
#define fi first
#define se second
#define endl '\n'

#define isOn(S, j) (S & (1 << j) )
#define setBit(S, j) (S |= (1 << j ) )
#define LSB(S) (S & (-S))

using namespace std;

long double x[1002], y[1002];
int n;

int main(){
	cin >> n;
	for(int i = 0; i < n; i++ )
		cin >> x[i] >> y[i];

	long double mn = 1e18; 
	for(int i = 0; i < n; i++){
		int a = ( i - 1 + n ) % n;
		int b = ( i + 1 ) % n;
		long double area = fabs( (y[b]-y[a])*x[i]-(x[b]-x[a])*y[i]+x[b]*y[a]-y[b]*x[a] );
		long double dist = hypot( y[b]-y[a], x[b]-x[a] );
		mn = min(mn, area/dist/2.0L); 
	}

	printf("%.6lf\n", (double)mn);

	return 0;
}