//In the name of Allah
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double ld; 
typedef pair<int,int> pii; 

void die(){ 
	cout << -1 << endl;
	exit(0); 
}

const int maxN = 100 * 1000 * 3 + 100;

pii a[maxN]; 
int p[maxN]; 

int main() { 
	ios::sync_with_stdio(false); cin.tie(0); 
	int n,k,s,t; cin >> n >> k >> s >> t; 
	if( t < s ) die(); 
	for( int i = 0 ; i < n ; i++ ) 
		cin >> a[i].second >> a[i].first;
	k++;
	for( int i = 1 ; i < k ; i++ ) 
		cin >> p[i]; 
	p[k++] = s; 

	sort( p , p + k ); 
	sort( a , a + n ); 
	int st = -1 , en = n; 
	while( en - st > 1 ) { 
		int m = (st+en) / 2; 

		int cap = a[m].first; 
		int speed = max(2 * s - t , 0) ; 
		bool canDo = true ;
		for( int i = 1 ; i < k ; i++ ) 
			if( p[i] - p[i-1] > cap ) { 
				canDo = false; 
				break; 
			} else 
				speed -= min( speed , min( p[i] - p[i-1] ,cap - (p[i] - p[i-1]) ) ); 
		if( canDo && speed == 0 ) en = m; 
		else st = m; 
	}
	if( en == n ) die(); 
	int mn = a[en].second; 
	for( int i = en + 1 ; i < n ; i++ ) 
		mn = min( mn , a[i].second ); 
	cout << mn << endl;
}