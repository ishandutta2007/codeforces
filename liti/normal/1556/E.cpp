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

const int N = 1000*100 + 100;

int a[N], b[N], c[N];
ll val[N]; 
ll psum[N]; 

int pl[N], pr[N], nl[N], nr[N]; 

ll segMin[4*N], segMax[4*N];

void build(int xl, int xr, int ind) { 
    if(xr - xl == 1) { 
        segMin[ind] = psum[xl];
        segMax[ind] = psum[xl]; 
        return;
    }
    int xm = (xl+xr)/2; 
    build(xl, xm, ind*2);
    build(xm, xr, ind*2+1);

    segMin[ind] = min(segMin[ind*2], segMin[ind*2+1]); 
    segMax[ind] = max(segMax[ind*2], segMax[ind*2+1]); 
}

ll get_min(int ql, int qr, int xl, int xr, int ind) { 
    if(xr <= ql || qr <= xl)
        return 1e18;
    if(ql <= xl && xr <= qr) 
        return segMin[ind]; 
    int xm = (xl+xr)/2;
    return min(get_min(ql, qr, xl, xm, ind*2),
            get_min(ql, qr, xm, xr, ind*2+1));
}

ll get_max(int ql, int qr, int xl, int xr, int ind) { 
    if(xr <= ql || qr <= xl)
        return -1e18;
    if(ql <= xl && xr <= qr) 
        return segMax[ind]; 
    int xm = (xl+xr)/2;
    return max(get_max(ql, qr, xl, xm, ind*2),
            get_max(ql, qr, xm, xr, ind*2+1));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); 

    int n, q;
    cin >> n >> q; 

    for(int i = 0; i < n; i++) 
        cin >> a[i]; 

    int last = -1;

    int Lneg = -1, Lpos = -1;

    for(int i = 0; i < n; i++) {
        cin >> b[i]; 

        c[i] = b[i] - a[i]; 

        if(c[i] != 0 && last >= 0 && 1ll * c[i] * c[last] > 0) 
            val[i] = val[last] + abs(c[i]);
        else
            val[i] = abs(c[i]);

        if(c[i] != 0)
            last = i;

        psum[i+1] = psum[i] + c[i]; 

        if(c[i] > 0)
            Lpos = i;
        else if(c[i] < 0)
            Lneg = i;

        pl[i] = Lpos;
        nl[i] = Lneg;
    }

    int Rneg = n, Rpos = n;
    for(int i = n-1; i >= 0; i--) {
        if(c[i] > 0)
            Rpos = i;
        else if(c[i] < 0)
            Rneg = i;

        pr[i] = Rpos;
        nr[i] = Rneg;
    }

    build(0, n, 1);

    for(int j = 0; j < q; j++) { 
        int ql, qr;
        cin >> ql >> qr; 
        ql--;
        qr--;

        if(pr[ql] > qr && nr[ql] > qr) 
            cout << 0 << '\n';
        else if(pr[ql] > nr[ql] || nl[qr] < pl[qr] || psum[qr+1] - psum[ql] != 0) {
            cout << -1 << '\n'; 
        } else {
            ql = pr[ql];
            qr = nl[qr];

            if(get_min(ql, qr+1, 0, n, 1) - psum[ql] < 0) {
                cout << -1 << '\n';
                continue;
            } 

            ll ans = get_max(ql, qr+1, 0, n, 1) - psum[ql];
            cout << ans << '\n';
        }
    }

    return 0;
}