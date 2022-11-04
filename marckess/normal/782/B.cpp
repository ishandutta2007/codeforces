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

#define ld long double
#define EPS 1e-11

ld x[60005], v[60005];
int n;

bool ispos(ld t){
	ld a = 1.0, b = 1e9;
	for(int i = 0; i < n; i++){
		ld izq = x[i] - v[i] * t;
		ld der = x[i] + v[i] * t;
		a = max ( a, izq );
		b = min ( b, der );
	}
	return a <= b ;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;

	for(int i = 0; i < n; i++)
		cin >> x[i];
	for(int i = 0; i < n; i++)
		cin >> v[i];

	ld i = 0.0, j = 1e9 + 5, m = (i+j)/2.0L;
	int rep = 60;
	while (rep--){
		if (ispos(m))
			j = m;
		else
			i = m;
		m = (i+j)/2.0L;
	}

	printf("%.6lf\n", (double)m );

	return 0;
}