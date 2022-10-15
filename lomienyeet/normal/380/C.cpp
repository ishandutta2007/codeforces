// got rid of my other template because *a few people will complain*
#include <bits/stdc++.h>
// #include <bits/extc++.h> // use if non-cf & non-c++20
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> // use if cf & C++20 (iconv.h got deprecated or sth i dont remember)
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define double long double
#define ff first
#define ss second
#define rofl exit(1);
#define debug(x) cerr<<(#x)<<"::"<<(x)<<"\n";
template<typename T> using OST=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
const int mod=1e9+7,mod2=998244353,inf=1e18;
void yes(){cout<<"YES\n";}
void no(){cout<<"NO\n";}
int bm(int b,int p,int m=mod){
    int ans=1;
    b%=m;
    while(p){
        if(p&1)(ans*=b)%=m;
        (b*=b)%=m;
        p>>=1;
    }
    return ans;
}
const int mxN=1e6+5;
string s;
int n;
struct node{
    int val,a,b;
}segtree[mxN<<2];
node merge(node aa,node bb){
    // write merge function later
    node ans;
    int z=min(aa.b,bb.a);
    ans.val=aa.val+bb.val+z*2;
    ans.a=aa.a+bb.a-z;
    ans.b=aa.b+bb.b-z;
    return ans;
}
void build(int idx,int l,int r){
    if(l==r){
        segtree[idx].val=0;
        segtree[idx].a=s[l]==')';
        segtree[idx].b=s[l]=='(';
        return;
    }
    int mid=(l+r)>>1;
    build(idx<<1,l,mid);
    build(idx<<1|1,mid+1,r);
    segtree[idx]=merge(segtree[idx<<1],segtree[idx<<1|1]);
}
node qry(int idx,int l,int r,int x,int y){
    if(x<=l&&r<=y)return segtree[idx];
    int mid=(l+r)>>1;
    if(x<=mid&&mid+1<=y)return merge(qry(idx<<1,l,mid,x,y),qry(idx<<1|1,mid+1,r,x,y));
    else if(x<=mid)return qry(idx<<1,l,mid,x,y);
    else return qry(idx<<1|1,mid+1,r,x,y);
}
void eat(){
    /* 
     */
    cin>>s;
    n=s.length();
    s="_"+s;
    build(1,1,n);
    int q;
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        cout<<qry(1,1,n,l,r).val<<"\n";
    }
    return;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	int t=1;
	//cin>>t;
	while(t--)eat();
}