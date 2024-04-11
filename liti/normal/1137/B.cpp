//be naame khodaa
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
#define F first
#define S second
#define pb push_back
#define sz(x) ((int)(x).size())

inline int in(){ int x, y; y = scanf("%d", &x); return x; }

const int N = 1000*1000+10;

int f[N]; 

int main(){
    ios::sync_with_stdio(false); cin.tie(0); 

    string s, t;
    cin >> s >> t;

    int s0 = 0, s1 = 0; 
    int t0 = 0, t1 = 0; 

    for(auto x : s) 
        if( x == '0' ) s0++;
        else s1++; 

    for(auto x : t ) 
        if( x == '0' ) t0++; 
        else t1++; 

    if( s0 >= t0 && s1 >= t1 ) { 
        cout << t ; 
        s0 -= t0; 
        s1 -= t1; 

        int curr = 0; 
        for(int i = 1; i < sz(t); i++) { 
            while( curr && t[i] != t[curr] )
                curr = f[curr]; 
            if( t[i] == t[curr] ) 
                curr++; 
            f[i+1] = curr; 
        }
        t0 = 0, t1 = 0; 
        for(int i = curr; i < sz(t); i++) 
            if( t[i] == '0' ) t0++; 
            else t1++; 
        t = t.substr(curr, sz(t) - curr); 

        int z = min( (t0?s0/t0:1000000) , (t1?s1/t1:1000000) );

        s0 -= t0 * z;
        s1 -= t1 * z;

        for(int i = 0; i < z; i++)
            cout << t ;
        for(int i = 0; i < s0; i++)
            cout << '0';
        for(int i = 0; i < s1; i++)
            cout << '1';
        cout << endl;
    } else { 
        cout << s << endl; 
    }

    return 0;
}