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

const int N = -1;

int ask(int x, int y) { 
    cout << "? " << x << " " << y << endl;
    fflush(stdout);
    string r;
    cin >> r;
    if( r == "x" ) return 1;
    assert( r != "e" );
    return 0;
}

void solve() { 
    int a = 0, b = 1; 

    while( !ask(a, b) ) {
        a = b;
        b = a * 2; 
    }

    int lo = a, hi = b;
    while( hi - lo > 1 ) { 
        int mid = (lo+hi)/2; 
        if( ask(a, mid) ) 
            hi = mid;
        else
            lo = mid; 
    }

    cout << "! " << hi << endl;
}

int main(){
    string s;
    while( cin >> s ) { 
        if( s == "end" || s == "mistake") break;
        if( s == "start" ) 
            solve();
    }
    return 0;
}