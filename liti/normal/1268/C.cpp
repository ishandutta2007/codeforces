//be naame khodaa
#include <algorithm>
#include <iostream>
#include <cassert>
#include <iomanip>
#include <cstring>
#include <sstream>
#include <numeric>
#include <string>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#include <set>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
#define F first
#define S second
#define pb push_back
#define sz(x) ((int)(x).size())

const int N = 200*1000 + 10;

pii a[N]; 
int fen[N]; 

ll seg[2][4*N], toadd[2][4*N]; 

void add(int x, int v) { 
    x++;  
    for(; x < N; x +=  x & -x) 
        fen[x] +=v;
}

int get(int x){ 
    int r  =  0;
    for(; x; x -= x & -x)
        r += fen[x];
    return r;
}

void sadd(int t, int ql, int qr, ll qv, int xl, int xr, int ind) {
    if( xr <= ql || qr <= xl ) return; 
    if( ql <= xl && xr <= qr ) { 
        toadd[t][ind] += qv;
        seg[t][ind] += qv * ll(xr-xl); 
        return;  
    }
    
    int xm = (xl+xr)/2;
    sadd(t, ql, qr, qv, xl, xm, ind * 2); 
    sadd(t, ql, qr, qv, xm, xr, ind * 2 + 1);

    seg[t][ind] = seg[t][ind*2] + seg[t][ind*2+1] + toadd[t][ind] * ll(xr-xl);
}

ll sget(int t, int ql, int qr, int xl, int xr, int ind) { 
    if( xr <= ql || qr <= xl ) return 0;
    if( ql <= xl && xr <= qr ) return seg[t][ind]; 

    int xm = (xl + xr)/2; 
    return sget(t, ql, qr, xl, xm, ind * 2) + sget(t, ql, qr, xm, xr, ind * 2 + 1) + toadd[t][ind] * ll(min(qr,xr)-max(ql,xl));
}

int main() {
    int n; 
    cin >> n;  

    for(int i = 0; i < n; i++) { 
        cin>>a[i].F; 
        a[i].S = i; 
    }

    sort(a, a + n);
    ll inv = 0; 
    for(int i = 0; i < n; i++)  { 
        int p = a[i].S; 

        inv += i - get(p); 
        add(p, 1); 

        sadd(0, 0, p+1, 1, 0, n, 1);
        sadd(1, p, n, 1, 0, n, 1); 

        int cnt = (i+2)/2;
        int lo = 0, hi = n; 
        while( hi - lo > 1 ) {
            int mid = (lo+hi)/2; 
            if( get(mid) < cnt )
                lo = mid;
            else
                hi = mid;
        }

        ll ret = inv + sget(1, 0, hi, 0, n, 1) + sget(0, hi, n, 0, n, 1); 

        int rem = i+1- cnt;

        ret -= cnt*ll(cnt+1)/2 + rem*ll(rem+1)/2;

        cout << ret << " ";
    }
    cout << endl;
}