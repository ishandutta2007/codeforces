
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

const int N = 4*100*1000 + 100;

int seg[4*N]; 
int mx[4*N], toadd[4*N]; 

struct Node { 
    int l, r; 
} node[N];

int a[N]; 
int mnL[N], mnR[N]; 

int M; 

void add(int ql, int qr, int qv, int xl = 0, int xr  = M,  int ind = 1  ) { 
    if( xr <= ql || qr <= xl ) 
        return; 

    if( ql <= xl && xr <= qr ) { 
        toadd[ind] += qv;
        mx[ind] += qv; 

        return;
    }

    int xm = (xl+xr) / 2; 
    add(ql, qr, qv, xl, xm, ind * 2); 
    add(ql, qr, qv, xm, xr, ind * 2 + 1); 

    mx[ind] = toadd[ind] + max(mx[ind*2], mx[ind*2+1]); 
}

int get(int ql, int qr, int xl = 0, int xr = M, int ind = 1 ) { 
    if( xr <= ql || qr <= xl ) 
        return 0; 
    if( ql <= xl && xr <= qr ) { 
        return mx[ind];  
    }

    int xm = (xl+xr)/2;
    return toadd[ind] + max(get(ql, qr, xl, xm, ind * 2), get(ql, qr, xm, xr, ind * 2 + 1));
}

void dfs(int s, int h) { 
    if( s == -1 ) return; 
    dfs( node[s].l, h + 1 ) ; 
    dfs( node[s].r, h + 1 ) ; 

    add(s, s+1, h); 
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 

    int n;
    cin >> n; 

    M = 2 * n;

    for(int i = 0; i < n; i++) 
        cin >> a[i]; 

    copy(a, a + n, a + n); 

    memset(mnL, -1, sizeof mnL); 
    memset(mnR, -1, sizeof mnR); 
    stack<int> st; 
    for(int i = 0; i < 2*n; i++) { 
        while( st.size() && a[st.top()] > a[i] ) 
            st.pop(); 

        if( st.size() ) 
            mnL[i] = st.top(); 
        st.push(i); 

        node[i].l = node[i].r = -1;
    }

    while(st.size())
        st.pop();

    for(int i = n - 1 ; i >= 0; i--) {
        while( st.size() && a[st.top()] > a[i] ) 
            st.pop(); 

        if( st.size() ) 
            mnR[i] = st.top(); 
        
        st.push(i); 

    }

    for(int i = 0; i < n; i++) { 
        if( mnR[i] + 1 && mnL[i] + 1 ) { 
            if( a[mnR[i]] > a[mnL[i]] ) 
                node[mnR[i]].l = i; 
            else
                node[mnL[i]].r = i; 
        } else if( mnR[i] + 1 ) 
            node[mnR[i]].l = i; 
        else if( mnL[i] + 1 )
            node[mnL[i]].r = i; 
    }

    while(st.size())
        st.pop();

    for(int i = 2*n - 1 ; i >= 0; i--) {
        while( st.size() && a[st.top()] > a[i] ) 
            st.pop(); 

        if( st.size() ) 
            mnR[i] = st.top(); 
        st.push(i); 

    }

    int s = min_element(a, a + n) - a; 
    
    dfs(s, 0); 

    int ans = get(0, n);
    int ind = 0;
    for(int i = 0; i < n; i++) { 

        if( a[i] == 1 ) { 
            node[i+n].l = node[i].r; 
        } else { 
            int p = mnR[i];
            add(i+1, p, -1); 
            node[p].l = node[i].r;

            p = mnL[i+n]; 
            add(p+1, n+i, 1);  
            node[n+i].l = node[p].r;
            node[p].r = n+i; 

            add(n+i, n+i+1, get(p, p+1) + 1); 

            int tmp = get(i+1, n+i+1);
            if( ans >  tmp ) {
                ans = tmp;
                ind = i+1; 
            }
        }
    }

    cout << ans+1 << ' ' << ind << endl;

    return 0;
}