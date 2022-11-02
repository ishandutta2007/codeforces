//In the name of Allah    
#include <bits/stdc++.h>    
using namespace std;    

#define __sz(x) ((int)(x).size())    
typedef long long ll;    

const int maxN = 1000*100 + 10;
pair<int,int> a[maxN];

int main() { 
	int n; 
	cin >> n;
	pair<int,int> best = {-1,-1}; 
	for( int i = 0 ; i < n ; i++ ) { 
		cin >> a[i].first >> a[i].second;
		best = max( best,make_pair( a[i].second - a[i].first , i ) ) ; 
	}
	int j = best.second;
	bool ch = false;
	for( int i = 0 ; i < n ; i++ ) 
		if( !( a[j].first <= a[i].first && a[i].second <= a[j].second ) )
			ch = true;
	if( !ch ) 
		cout << j + 1 << endl;
	else
		cout << -1 << endl;
}