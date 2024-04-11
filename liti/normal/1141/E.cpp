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

const int N = 2*1000*100 + 10;

ll a[N]; 

void die(ll x) { 
    cout << x << endl;
    exit(0);
}

int main() {
    ll H; 
    int n;

    cin >> H >> n;
    ll mn = 0; 
    for(int i = 0; i < n; i++) {
        cin >> a[i+1]; 
        a[i+1] += a[i]; 

        mn = min(mn, a[i+1]); 

        if( H + a[i+1] <= 0 ) 
            die(i+1); 
    }

    if( a[n] >= 0 ) 
        die(-1); 

    ll diff = (H+mn-1) / (-a[n]); 
    ll ans = diff * 1ll * n; 


    H += diff * 1ll * a[n]; 

    for(int i = 0; ; i = (i+1) % n ) {
        ans++; 
        H += a[i+1] - a[i]; 
        if( H <= 0 ) die(ans); 
    }

    return 0;
}