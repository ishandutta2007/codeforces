//In the name of Allah    
#include <bits/stdc++.h>    
using namespace std;    

#define sz(x) ((int)(x).size())    
typedef long long ll    ;

const int maxN = 1000*100 + 100; 
int pre[maxN];
int suf[maxN];
string t = "CODEFORCES";
int main() { 
    string s;
    cin >> s; 

    int n = sz(s);
    int m = sz(t);
    for( int i = 0 ; i < n ; i++ ) 
	if(  i < sz(t) && s[i] == t[i] ) 
	    pre[i] = i + 1 ; 
	else
	    break;
    for( int i = 0 ; i < n ; i++ ) 
	if( i < sz(t) && s[n-i-1] == t[m-i-1] ) 
	    suf[n-i-1] = i + 1; 
	else
	    break;

    int mx = 0 ; 
    for( int i = n - 1 ; i >= 0 ; i-- ) { 
	if( mx + pre[i] >= m ) {
	    cout << "YES" << endl;
	    return 0;
	}
	mx = max( mx , suf[i] ) ; 
    }
    cout << "NO" << endl;
}