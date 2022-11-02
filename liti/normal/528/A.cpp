/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;

#define sz(x) (((int) x.size()))
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,pii> piii;

set<int> H , V; 
set<piii,greater<piii>> currH, currV; 

int main() {
	ios::sync_with_stdio(false);
	int w,h,n;
	cin >> w >> h >> n; 

	V.insert(0); 
	V.insert(w); 
	H.insert(h);
	H.insert(0); 

	currH.insert( { h , { 0 , h } } ) ; 
	currV.insert( { w , { 0 , w } } ) ; 

	for( int i = 0 ; i < n ; i++ ) { 
		char ch; 
		int v; 
		cin >> ch >> v; 
		if( ch == 'H' ) { 
			auto it = H.insert( v ).first ; 
			auto prv = --it; 
			++it; ++it;
			auto nxt = it;
			--it;
			currH.erase( { * nxt - * prv , { *prv , *nxt } } ) ; 
			currH.insert( { * nxt - *it , { *it , *nxt } } ) ; 
			currH.insert( { * it - *prv , { *prv , *it } } ) ; 
		} else { 
			auto it = V.insert( v ).first ; 
			auto prv = --it; 
			++it; ++it;
			auto nxt = it;
			--it;
			currV.erase( { * nxt - * prv , { *prv , *nxt } } ) ; 
			currV.insert( { * nxt - *it , { *it , *nxt } } ) ; 
			currV.insert( { * it - *prv , { *prv , *it } } ) ; 
		}
		cout << ll( currV.begin()->first ) * currH.begin()->first << endl;
	}
}