//In the name of Allah    
#include <bits/stdc++.h>    
using namespace std;    

#define __sz(x) ((int)(x).size())    
typedef long long ll;    
typedef pair<int,int> pii;
typedef pair<pii,int> piii;

const int maxN = 1000*1000 + 1000;
piii a[maxN];
const int k = 1001; 

bool cmp( piii aa , piii bb ) { 
	pii a = aa.first , b = bb.first;
	int p1 = a.first / k; 
	int p2 = b.first / k; 
	if( p1 != p2 ) 
		return p1 < p2;
	if( p1 & 1 ) 
		return a.second < b.second;
	return b.second < a.second;
}

int main() { 
	ios::sync_with_stdio(false); cin.tie(0);
	int n; 
	cin >> n; 
	for( int i = 0 ; i < n ; i++ ) {
		cin >> a[i].first.first >> a[i].first.second;
		a[i].second = i + 1;
	}
	sort( a , a + n , cmp ) ; 
	for( int i = 0 ; i < n;  i++ )  
		cout << a[i].second << ' ' ;
	cout << endl;
}