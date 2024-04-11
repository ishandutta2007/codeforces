#include<bits/stdc++.h>
#define int long long
#define double long double
#define pb push_back
#define sp ' '
#define endl '\n'
#define fi first
#define se second
using namespace std;
const int mod=1e9+7;
const int N=3e5+5;
const int A=1e6+5;
const double pi=acos(-1);
typedef pair<int,int> ii;
int divs[A];
int n,m,a[N];
void prepare(){for(int i=1; i<A; ++i)for(int j=i; j<A; j+=i) ++divs[j];}
struct _node{
	int sm;
	int mx;
}node[N<<2];
void build(int i, int l, int r)
{
if(l>r) return;
if(l==r){ node[i].sm= node[i].mx= a[l];return;}
int mid=l+r>>1;
build( i<<1, l, mid);
build( i<<1|1, mid+1, r);
node[i].sm= node[i<<1].sm+ node[i<<1|1].sm;
node[i].mx=max( node[i<<1].mx, node[i<<1|1].mx);
}
void update(int i,int l,int r,int L,int R)
{
	if(l>r || L>r || R<l)return;
	if(node[i].mx<=2)return;
	if(l==r) {node[i].sm= node[i].mx= a[l]= divs[a[l]]; return;}
	int mid=l+r>>1;
	update(i<<1, l, mid, L, R);
	update(i<<1|1,mid+1,r,L,R);
	node[i].sm= node[i<<1].sm+ node[i<<1|1].sm;
	node[i].mx=max( node[i<<1].mx, node[i<<1|1].mx);
}
int get(int i,int l,int r,int L,int R)
{
if(l>r || L>r || R<l) return 0;
if(L<=l && R>=r)return node[i].sm;
int mid=l+r>>1;
return get(i<<1,l,mid,L,R)+get(i<<1|1,mid+1, r, L,R);
}
signed main()
{
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
prepare();
cin>>n>>m;
for(int i=1;i<=n;++i)cin>>a[i];
build(1,1,n);
//cout<<"lomzom"<<endl;
while(m--)
{
	int type,l,r;
	cin>>type>>l>>r;
	if(type==1) update(1,1,n,l,r);
	else cout<<get(1,1,n,l,r)<<endl;
	/*for(int i=1;i<=n;++i)cout<<a[i]<<sp;
	cout<<endl;*/
}
}