#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define ls(x) ((x)<<1)
#define rs(x) ((x)<<1|1)
using namespace std;
int const N=400010,INF=0x3f3f3f3fll,M=2333333;
int n,q,cur,tot,ql,qr,p,k,sl[N],sr[N],a[N],tr[N],ans[N],seq[M],l[N],r[N];
struct node{
	int l,r,id;
	int operator<(const node&rhs)const{
		return r<rhs.r;
	}
}b[N];
void update(int x){
	cur=min(cur,tr[x]=min(tr[x],min(tr[ls(x)],tr[rs(x)])));
}
void build(int x,int al,int ar){
	l[x]=al,r[x]=ar;
	if(al==ar){
		seq[sl[x]=sr[x]=++tot]=a[al];
		return;
	}
	int mid=(al+ar)>>1;
	build(ls(x),al,mid);
	build(rs(x),mid+1,ar);
	sl[x]=tot+1;
	int lson=ls(x),rson=rs(x),p1=sl[lson],p2=sl[rson];
	while(p1<=sr[lson]&&p2<=sr[rson])
		if(seq[p1]<seq[p2])
			seq[++tot]=seq[p1++];
		else
			seq[++tot]=seq[p2++];
	while(p1<=sr[lson])
		seq[++tot]=seq[p1++];
	while(p2<=sr[rson])
		seq[++tot]=seq[p2++];
	sr[x]=tot;
}
void modify(int x){
	if(r[x]<=p){
		int i=upper_bound(seq+sl[x],seq+sr[x]+1,k)-seq;
		if(i!=sr[x]+1)
			tr[x]=min(tr[x],seq[i]-k);
		if(i!=sl[x])
			tr[x]=min(tr[x],k-seq[i-1]);
		if(cur<=tr[x])
			return;
		if(l[x]==r[x]){
			cur=tr[x];
			return;
		}
	}
	int mid=(l[x]+r[x])>>1;
	if(p>mid)
		modify(rs(x));
	modify(ls(x));
	update(x);
}
int query(int x){
	if(ql<=l[x]&&r[x]<=qr)
		return tr[x];
	int mid=(l[x]+r[x])>>1,res=INF;
	if(ql<=mid)
		res=min(res,query(ls(x)));
	if(qr>mid)
		res=min(res,query(rs(x)));
	return res;
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	memset(tr,0x3f,sizeof tr);
	build(1,1,n);
	cin>>q;
	for(int i=1;i<=q;i++)
		cin>>b[i].l>>b[i].r,b[i].id=i;
	sort(b+1,b+1+q);
	for(int i=2,j=1;i<=n;i++){
		cur=INF;
		p=i-1,k=a[i],modify(1);
		for(;j<=q&&b[j].r<=i;j++)
			ql=b[j].l,qr=i,ans[b[j].id]=query(1);
	}
	for(int i=1;i<=q;i++)
		cout<<ans[i]<<"\n";
}