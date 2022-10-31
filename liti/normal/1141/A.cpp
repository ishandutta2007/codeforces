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

void die() { 
    cout << -1 << endl;
    exit(0); 
}

int main(){
    int n, m;
    cin >> n >> m;
    if( m % n ) 
        die();
     
    m /= n; 
    int ans = 0; 
    while( m % 2 == 0 ) { 
        m/=2;
        ans++; 
    }
    while( m % 3 == 0 ) { 
        m /= 3; 
        ans++; 
    }
    if( m == 1 ) 
        cout << ans << endl;
    else
        die();
    return 0;
}