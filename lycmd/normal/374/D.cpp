#include<bits/stdc++.h>
#define ls(x) ((x)<<1)
#define rs(x) ((x)<<1|1)
using namespace std;
int const N=4000010,K=1000000;
int n,m,w,a[N],tr[N],vis[N],s[N],p[N];
void update(int x){
	tr[x]=tr[ls(x)]+tr[rs(x)];
}
void modify(int x,int l,int r,int p,int k){
	if(l==r)
		return tr[x]=k,void();
	int mid=(l+r)>>1;
	if(p<=mid)
		modify(ls(x),l,mid,p,k);
	else
		modify(rs(x),mid+1,r,p,k);
	update(x);
}
int find(int x,int l,int r,int k){
	if(l==r)
		return l;
	int mid=(l+r)>>1;
	return k<=tr[ls(x)]?find(ls(x),l,mid,k):find(rs(x),mid+1,r,k-tr[ls(x)]);
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=m;i++)
		cin>>a[i];
	while(n--){
		int x;cin>>x;
		if(~x)
			s[++w]=x,modify(1,1,K,w,1);
		else{
			int t=m;
			for(int i=1;i<=m;i++)
				if(a[i]>tr[1]){
					t=i-1;break;
				}else p[i]=find(1,1,K,a[i]);
			for(int i=1;i<=t;i++)
				modify(1,1,K,p[i],0),vis[p[i]]=1;
		}
	}
	int flg=1;
	for(int i=1;i<=w;i++)
		if(!vis[i])
			cout<<s[i],flg=0;
	if(flg)
		cout<<"Poor stack!\n";
}