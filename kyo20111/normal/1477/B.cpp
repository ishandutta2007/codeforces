#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define mid ((l+r) >> 1)

int n, m, t[800800], lz[800800], l[200200], r[200200];
string s, f;

void lazy_update(int node, int l, int r){
    if(lz[node] != -1){
        t[node] = (r-l+1) * lz[node];
        if(l != r) lz[node*2] = lz[node*2+1] = lz[node];
        lz[node] = -1;
    }
}

void update(int nl, int nr, int val, int node = 1, int l = 1, int r = n){
    lazy_update(node, l, r);
    if(nr < l || r < nl) return;
    if(nl <= l && r <= nr){
        lz[node] = val;
        lazy_update(node, l, r);
        return;
    }
    update(nl, nr, val, node*2, l, mid), update(nl, nr, val, node*2+1, mid+1, r);
    t[node] = t[node*2] + t[node*2+1];
}

int find(int nl, int nr, int node = 1, int l = 1, int r = n){
    lazy_update(node, l, r);
    if(nr < l || r < nl) return 0;
    if(nl <= l && r <= nr) return t[node];
    return find(nl, nr, node*2, l, mid) + find(nl, nr, node*2+1, mid+1, r);
}

void solve(){
    cin >> n >> m >> s >> f;

    for(int i=1;i<=4*n;i++) t[i] = 0, lz[i] = -1;
    for(int i=1;i<=n;i++) if(f[i-1] == '1') update(i, i, 1);

    for(int i=1;i<=m;i++) cin >> l[i] >> r[i];

    for(int i=m;i>=1;i--){
        int len = r[i]-l[i]+1, k = find(l[i], r[i]);

        if(len % 2 == 0 && k == len/2){
            cout << "NO";
            return;
        }

        if(k < (len+1)/2){
            update(l[i], r[i], 0);
        }else{
            update(l[i], r[i], 1);
        }
    }

    for(int i=1;i<=n;i++) if(find(i, i) != s[i-1] - '0'){
        cout << "NO";
        return;
    }
    cout << "YES";
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int tc; cin >> tc;
    while(tc--){
        solve();
        cout << "\n";
    }
}