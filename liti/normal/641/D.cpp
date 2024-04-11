//In the name of Allah
#include <bits/stdc++.h>
using namespace std;

typedef long double ld; 
const int maxN = 1000 * 100 + 100; 
ld a[maxN], b[maxN];

inline pair<ld,ld> calc( ld a , ld b , ld c , int step  ) { 
	ld delta = b * b - 4 * a * c; 
	delta = sqrt(abs(delta)); 
	return { (-b - delta) / (2*a) , (-b+delta) / (2*a) } ; 
}

ld p[maxN], q[maxN];
int main() { 
	ios::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n; 
	for( int i = 0 ; i < n ; i++ ) 
		cin >> a[i]; 
	for( int j = 0 ; j < n ; j++) 
		cin >> b[j]; 

	cout << fixed << setprecision(8) ; 
	ld sumA = 0 , sumB = 0 ; 
	for( int i = 0 ; i < n ; i++ ) { 
		ld C = a[i] + b[i];
		ld a = -1; 
		ld b = sumB - sumA + C; 
		ld c = C * sumA - ::a[i]; 
		pair<ld,ld> ret = calc( a , b , c , i ) ; 
		ret.second = C - ret.first;
		p[i] = ret.first; 
		q[i] = ret.second;
		sumA += p[i]; 
		sumB += q[i];
	}
	for( int i =0 ; i < n ; i++ ) 
		cout << p[i] << ' ';
	cout << endl;	
	for( int i = 0 ; i < n ; i++ ) 
		cout << q[i] << ' ' ; 
	cout << endl;
}