#include<bits/stdc++.h>
#define int long long
#define ls(x) ((x)<<1)
#define rs(x) ((x)<<1|1)
using namespace std;
int const N=3000010;
int n,tr[N],clt[N],flt[N];
vector<int>b;
array<int,3>a[N];
void update(int x){
	tr[x]=tr[ls(x)]+tr[rs(x)];
}
void cov(int x,int k,int d){
	flt[x]=0,clt[x]=k,tr[x]=d*k;
}
void rev(int x,int d){
	tr[x]=d-tr[x];
	(~clt[x]?clt[x]:flt[x])^=1;
}
void download(int x,int l,int r){
	int mid=(l+r)>>1,&tc=clt[x],&tf=flt[x];
	if(~tc)cov(ls(x),tc,mid-l+1),cov(rs(x),tc,r-mid),tc=-1;
	if(tf)rev(ls(x),mid-l+1),rev(rs(x),r-mid),tf=0;
}
void cover(int x,int l,int r,int ql,int qr,int k){                
	if(ql<=l&&r<=qr){
		cov(x,k,r-l+1);
		return;
	}
	download(x,l,r);
	int mid=(l+r)>>1;
	if(ql<=mid)cover(ls(x),l,mid,ql,qr,k);
	if(qr>mid)cover(rs(x),mid+1,r,ql,qr,k);
	update(x);
}
void flip(int x,int l,int r,int ql,int qr){
	if(ql<=l&&r<=qr){
		rev(x,r-l+1);
		return;
	}
	download(x,l,r);
	int mid=(l+r)>>1;
	if(ql<=mid)flip(ls(x),l,mid,ql,qr);
	if(qr>mid)flip(rs(x),mid+1,r,ql,qr);
	update(x);
}
int query(int x,int l,int r){
	if(l==r)return l;
	download(x,l,r);
	int mid=(l+r)>>1;
	return tr[ls(x)]<mid-l+1?query(ls(x),l,mid):query(rs(x),mid+1,r);
}
signed main(){
	ios::sync_with_stdio(0);
	cin>>n;
	b.push_back(0);
	b.push_back(1);
	for(int i=1;i<=n;i++){
		for(int j=0;j<3;j++)
			cin>>a[i][j];
		for(int j=1;j<3;j++)
			b.push_back(a[i][j]-1),
			b.push_back(a[i][j]),
			b.push_back(a[i][j]+1);
	}
	sort(b.begin(),b.end());
	b.erase(unique(b.begin(),b.end()),b.end());
	for(int i=1;i<=n;i++)
		for(int j=1;j<3;j++)
			a[i][j]=lower_bound(b.begin(),b.end(),a[i][j])-b.begin();
	memset(clt,-1,sizeof clt);
	int k=b.size();
	for(int i=1;i<=n;i++){
		int op=a[i][0],l=a[i][1],r=a[i][2];
		switch(op){
			case 1:cover(1,1,k,l,r,1);break;
			case 2:cover(1,1,k,l,r,0);break;
			case 3:flip(1,1,k,l,r);break;
		}
		cout<<b[query(1,1,k)]<<"\n";
	}
}