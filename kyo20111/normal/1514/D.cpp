#include<bits/stdc++.h>
using namespace std;
struct query{
    int l, r, id;
    bool operator < (const query &o) const{
        return make_pair(l >> 9, r) < make_pair(o.l >> 9, o.r);
    }
}q[300300];
int n, m, ans[300300], a[300300], chk[300300], cnt[300300], mx, mxn;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=m;i++) cin >> q[i].l >> q[i].r, q[i].id = i;
    sort(q+1, q+1+m);
    int l = 1, r = 0;
    for(int i=1;i<=m;i++){
        while(r < q[i].r) if(cnt[++chk[a[++r]]]++ == 0) mx++;
        while(l > q[i].l) if(cnt[++chk[a[--l]]]++ == 0) mx++;
        while(r > q[i].r) if(cnt[chk[a[r--]]--]-- == 1) mx--;
        while(l < q[i].l) if(cnt[chk[a[l++]]--]-- == 1) mx--;

        int len = r-l+1;
        int x = len - mx;
        ans[q[i].id] = 1 + max(0, mx - (x+1));
    }
    
    for(int i=1;i<=m;i++) cout << ans[i] << '\n';
}