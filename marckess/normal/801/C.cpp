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

vector<pair<long double, long double> > v;
ll n, p; 

bool ispos ( long double m ){
	long double sum = 0;
	for(int i = 0; i < n; i++){
		II d = v[i];
		sum += max(0.0L, m * d.fi - d.se) / m;
	}
	return sum <= p;
}

int main(){cin >> n >> p;
	ll sum = 0, a, b, x;
	for(int i = 0; i < n; i++){
		cin >> a >> b;
		v.push_back(make_pair((long double)a, (long double)b));
		sum += a;
	}

	if ( sum <= p ){
		cout << -1;
		return 0;
	}

	long double i = 0.0L, j = 1e10L, m = (i+j)/2.0L;
	ll rep = log2(1e15);
	while(rep--){
		if ( ispos( m ) )
			i = m;
		else
			j = m;
		m = (i+j)/2.0L;
	}

	printf("%.4lf\n", (double)m);

	return 0;
}