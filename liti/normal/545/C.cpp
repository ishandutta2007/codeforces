//In the name of Allah    
#include <bits/stdc++.h>    
using namespace std;    

#define __sz(x) ((int)(x).size())    
typedef long long ll;    
typedef pair<int,int> pii;

const int maxN = 1000*100 + 100; 
int h[maxN], x[maxN];

int main() { 
    int n;
    cin >> n;
    for( int i = 0 ; i < n ; i++ ) 
	cin >> x[i] >> h[i];
    int ans = 1; 
    int mx = x[0] ; 
    x[n] = 2e9 + 100;
    for( int i = 1 ; i < n ; i++ ) 
	if( x[i] - h[i] > mx ) { 
	    mx = x[i]; 
	    ans++; 
	} else if( x[i] + h[i] < x[i+1] ) {
	    ans++; 
	    mx = x[i] + h[i]; 
	} else 
	    mx = x[i];
    cout << ans<< endl;
}