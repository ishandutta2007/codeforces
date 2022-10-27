# include <iostream>
# include <cmath>
# include <algorithm>
# include <stdio.h>
# include <cstdint>
# include <cstring>
# include <string>
# include <cstdlib>
# include <vector>
# include <bitset>
# include <map>
# include <queue>
# include <ctime>
# include <stack>
# include <set>
# include <list>
# include <random>
# include <deque>
# include <functional>
# include <iomanip>
# include <sstream>
# include <fstream>
# include <complex>
# include <numeric>
# include <immintrin.h>
# include <cassert>
# include <array>
# include <tuple>
# include <unordered_set>
# include <unordered_map>
using namespace std;
 
const int inf=2e9;
const int N=100002;
const int K=300002;
 
 
int n,m,C,k;
int sz,all;
int lft[K*74],rght[K*74],t[K*74];
int root[K+5];
pair<pair<int,int>,int> seg[K+5];
 
 
inline void init_segment_tree() {
    sz=1;
    while (sz<n) sz+=sz;
    all=sz+sz;
    for (int i=1;i<sz;++i) {
        lft[i]=i+i;
        rght[i]=i+i+1;
    }
    for (int i=1;i<=all;++i)
        t[i]=inf;
}
 
 
////////////////////////// SEGMENT TREE
 
inline int vcopy(int &x) {
    ++all;
    lft[all]=lft[x];
    rght[all]=rght[x];
    t[all]=t[x];
    return all;
}
 
void update(int l,int r,int ll,int x,int y) {
    if (l==r) {
        if (y<t[x]) t[x]=y;
        return;
    }
    int mid=(l+r)>>1;
    if (ll<=mid) {
        lft[x]=vcopy(lft[x]);
        update(l,mid,ll,lft[x],y);
    } else {
        rght[x]=vcopy(rght[x]);
        update(mid+1,r,ll,rght[x],y);
    }
    y=t[lft[x]];
    if (y<t[rght[x]]) y=t[rght[x]];
    t[x]=y;
}
 
int get(int l,int r,int ll,int rr,int x) {
    if (l>r || ll>r || l>rr || ll>rr) return 0;
    if (l>=ll && r<=rr) return t[x];
    int mid=(l+r)>>1;
    return max(get(l,mid,ll,rr,lft[x]),get(mid+1,r,ll,rr,rght[x]));
}
 
//////////////////////////////////////////////////////////////////////
 
inline void build_segment_tree(int &C) {
    root[C+1]=1;
    for (int i=C;i>0;--i) {
        root[i]=vcopy(root[i+1]);
        update(1,sz,seg[i].second,root[i],seg[i].first.second);
    }
}
 
inline int get_pos(int &x) {
    int l=1,r=C;
    int mid;
    while (l<r-1) {
        mid=(l+r)>>1;
        if (seg[mid].first.first>=x) r=mid;
        else l=mid;
    }
    if (seg[l].first.first>=x) r=l;
    if (seg[r].first.first>=x) return r;
    return C+1;
}
 
 
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m>>k;
    int x,y,c;
    for (int i=1;i<=k;++i) {
        cin>>x>>y>>c;
        seg[++C]=make_pair(make_pair(x,y),c);
    }
    init_segment_tree();
 
    sort(seg+1,seg+C+1);
    build_segment_tree(C);
 
    int l, r, pos;
 
    for (int i=1;i<=m;++i) {
        cin>>l>>r>>x>>y;
        pos=get_pos(x);
        if (pos>C) {
            cout<<"no"<<endl;
            continue;
        }
        if (get(1,sz,l,r,root[pos])>y) cout<<"no";
        else cout<<"yes";
        cout<<endl;
    }
 
}