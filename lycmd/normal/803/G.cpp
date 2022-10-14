#include<bits/stdc++.h>
using namespace std;
int const N=100010,B=18,T=27000010;
int n,k,q,tot,rt,tflg,a[N],f[B][N],lg[N],tr[T],lt[T],ls[T],rs[T];
bitset<T>flg;
int ask(int l,int r){
	int k=lg[r-l+1];
	return min(f[k][l],f[k][r-(1<<k)+1]);
}
int lask(int l,int r){
	int bl=(l-1)/n,br=(r-1)/n;
	if(br-bl>1)return ask(1,n);
	if(bl==br)return ask(l-bl*n,r-bl*n);
	return min(ask(l-bl*n,n),ask(1,r-br*n));
}
int newnode(int l,int r){
	return tr[++tot]=lask(l,r),tot;
}
void update(int x,int l,int r){
	int mid=(l+r)>>1;
	if(!ls[x])tr[x]=min(lask(l,mid),tr[rs[x]]);
	else if(!rs[x])tr[x]=min(tr[ls[x]],lask(mid+1,r));
	else tr[x]=min(tr[ls[x]],tr[rs[x]]);
}
void download(int x){
	if(!flg[x])return;
	if(!ls[x])ls[x]=++tot;
	if(!rs[x])rs[x]=++tot;
	tr[ls[x]]=tr[rs[x]]=lt[x];
	lt[ls[x]]=lt[rs[x]]=lt[x];
	flg[ls[x]]=flg[rs[x]]=1;
	flg[x]=0;
}
void modify(int&x,int l,int r,int ql,int qr,int k){
	if(!x)x=newnode(l,r);
	if(ql<=l&&r<=qr){
		tr[x]=lt[x]=k,flg[x]=1;
		return;
	}
	download(x);
	int mid=(l+r)>>1;
	if(ql<=mid)modify(ls[x],l,mid,ql,qr,k);
	if(qr>mid)modify(rs[x],mid+1,r,ql,qr,k);
	update(x,l,r);
}
int query(int&x,int l,int r,int ql,int qr){
	if(!tflg)return lask(ql,qr);
	if(!x)x=newnode(l,r);
	if(ql<=l&&r<=qr)
		return tr[x];
	download(x);
	int mid=(l+r)>>1,res=INT_MAX;
	if(ql<=mid)res=min(res,query(ls[x],l,mid,ql,qr));
	if(qr>mid)res=min(res,query(rs[x],mid+1,r,ql,qr));
	return res;
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i],f[0][i]=a[i];
	for(int i=2;i<N;i++)
		lg[i]=lg[i>>1]+1;
	for(int i=1;i<B;i++)
		for(int j=1;j<=n-(1<<(i-1));j++)
			f[i][j]=min(f[i-1][j],f[i-1][j+(1<<(i-1))]);
	for(cin>>q;q--;){
		int op,l,r,x;
		cin>>op>>l>>r;
		if(op<2)
			cin>>x,modify(rt,1,n*k,l,r,x),tflg=1;
		else
			cout<<query(rt,1,n*k,l,r)<<"\n";
	}
}