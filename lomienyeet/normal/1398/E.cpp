//  n << 5 

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ff first
#define ss second
const int mxN=2e5+5,inf=1e9;
struct node{
    int sum,sum2,lc,rc;
}segtree[mxN<<5];
int cur,cnt; // i forgot how to build a persistent so just maintain current node while going through
void upd(int &idx,int l,int r,int x,int v){
    if(!idx)idx=++cnt;
    segtree[idx].sum+=x*v;
    segtree[idx].sum2+=v;
    if(l==r)return;
    int mid=(l+r)>>1;
    if(x<=mid)upd(segtree[idx].lc,l,mid,x,v);
    else upd(segtree[idx].rc,mid+1,r,x,v);
}
int qry(int idx,int l,int r,int k){
    if(!k)return 0;
    if(l==r)return l*k;
    int mid=(l+r)>>1;
    if(segtree[segtree[idx].rc].sum2>=k)return qry(segtree[idx].rc,mid+1,r,k);
    else return segtree[segtree[idx].rc].sum+qry(segtree[idx].lc,l,mid,k-segtree[segtree[idx].rc].sum2);
}
signed main(){
    int n,s=0;
    cin>>n;
    multiset<int> ms,sm;
    pair<int,int> wao={0,0};
    while(n--){
        int op,x;
        cin>>op>>x;
        s+=x;
        if(!op){
            if(x<0){
                ms.erase(-x);
                upd(cur,-inf,inf,-x,-1);
            }
            else{
                ms.insert(x);
                upd(cur,-inf,inf,x,1);
            }
        }
        else{
            if(x<0){
                sm.erase(-x);
                wao.ff+=x;
                wao.ss--;
                upd(cur,-inf,inf,-x,-1);
            }
            else{
                sm.insert(x);
                wao.ff+=x;
                wao.ss++;
                upd(cur,-inf,inf,x,1);
            }
        }
        int ans=qry(cur,-inf,inf,wao.ss);
        if(ans==wao.ff&&wao.ss>0){
            ans-=(*sm.begin());
            if(ms.size())ans+=(*ms.rbegin());
        }
        cout<<s+ans<<"\n";
    }
}