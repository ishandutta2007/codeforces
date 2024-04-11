#include<bits/stdc++.h>
#define ls(x) ((x)<<1)
#define rs(x) ((x)<<1|1)
using namespace std;
int const N=1000010,T=N<<2,INF=0x3f3f3f3f;
int n,cur=1,c[N],mx[T],mn[T],lt[T];
string s;
void update(int x){
	mx[x]=max(mx[ls(x)],mx[rs(x)]);
	mn[x]=min(mn[ls(x)],mn[rs(x)]);
}
void add(int x,int k){
	lt[x]+=k,mx[x]+=k,mn[x]+=k;
}
void download(int x){
	int&t=lt[x];
	add(ls(x),t),add(rs(x),t),t=0;
}
void modify(int x,int l,int r,int ql,int qr,int k){
	if(ql<=l&&r<=qr){
		add(x,k);return;
	}
	download(x);
	int mid=(l+r)>>1;
	if(ql<=mid)modify(ls(x),l,mid,ql,qr,k);
	if(qr>mid)modify(rs(x),mid+1,r,ql,qr,k);
	update(x);
}
int querymin(int x,int l,int r,int ql,int qr){
	if(ql<=l&&r<=qr)
		return mn[x];
	download(x);
	int mid=(l+r)>>1,res=INF;
	if(ql<=mid)res=min(res,querymin(ls(x),l,mid,ql,qr));
	if(qr>mid)res=min(res,querymin(rs(x),mid+1,r,ql,qr));
	return res;
}
int querymax(int x,int l,int r,int ql,int qr){
	if(ql<=l&&r<=qr)
		return mx[x];
	download(x);
	int mid=(l+r)>>1,res=-INF;
	if(ql<=mid)res=max(res,querymax(ls(x),l,mid,ql,qr));
	if(qr>mid)res=max(res,querymax(rs(x),mid+1,r,ql,qr));
	return res;
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>s;
	for(int i=0;i<n;i++){
		switch(s[i]){
			case'R':cur++;break;
			case'L':if(cur>1)cur--;break;
			case'(':modify(1,1,n,cur,n,1-c[cur]),c[cur]=1;break;
			case')':modify(1,1,n,cur,n,-1-c[cur]),c[cur]=-1;break;
			default:modify(1,1,n,cur,n,-c[cur]),c[cur]=0;break;
		}
		if(querymin(1,1,n,n,n)||querymin(1,1,n,1,n)<0)
			cout<<"-1 ";
		else
			cout<<querymax(1,1,n,1,n)<<" ";
	}
}