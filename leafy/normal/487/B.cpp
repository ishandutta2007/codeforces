#include<bits/stdc++.h>
using namespace std;
const int N=100005,inf=0x3f3f3f3f;
inline int read(){
	int s=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)) s=s*10+ch-'0',ch=getchar();
	return s*f;
}
int n,L,S;
int a[N],mn[N];
multiset<int> s;
inline bool check(int x){
	if(s.empty()) return 1;
	multiset<int>::iterator it=s.end();--it;
	if(abs(x-(*s.begin()))<=S&&abs(x-(*it))<=S) return 1;
	return 0;
}
int mx[N<<2];
#define ls rt<<1
#define rs rt<<1|1
inline void update(int rt,int l,int r,int p,int c){
	if(l==r){mx[rt]=c;return;}
	int mid=(l+r)>>1;
	if(p<=mid) update(ls,l,mid,p,c);
	else update(rs,mid+1,r,p,c);
	mx[rt]=min(mx[ls],mx[rs]);
}
inline int query(int rt,int l,int r,int L,int R){
	if(L<=l&&r<=R) return mx[rt];
	int mid=(l+r)>>1,res=inf;
	if(L<=mid) res=min(res,query(ls,l,mid,L,R));
	if(R>mid) res=min(res,query(rs,mid+1,r,L,R));
	return res;
}
int f[N];
int main(){
	n=read(),S=read(),L=read();
	for(int i=1;i<=n;i++) a[i]=read();
	int la=0;
	for(int i=1;i<=n;i++){
		while(la<n&&check(a[la+1])){
			la++;s.insert(a[la]);
			mn[la]=i;
		}
		multiset<int>::iterator it=s.find(a[i]);
		s.erase(it);
	}
	//update(1,1,n+1,1,0);
	//for(int i=2;i<=n+1;i++) update(1,1,n+1,i,inf);
	for(int i=1;i<=n;i++){
		int l=mn[i]-1,r=i-L;
	//	cout<<l<<' '<<r<<endl;
		if(l>r||r<0) f[i]=inf;
		else {
			f[i]=query(1,1,n+1,l+1,r+1)+1;
		}
	//	cout<<f[i]<<endl;
		update(1,1,n+1,i+1,f[i]);
	}
	printf("%d\n",f[n]>=inf?-1:f[n]);
	return 0;
}
/*
6 565 2

31 76 162 -182 -251 214

*/