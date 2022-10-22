#include<bits/stdc++.h>
using namespace std;
const int N=200010;
int n,t;
long long int a[N],ca[N];
long long int gcd(long long int x,long long int y){
	if(y==0)return x;
	return gcd(y,x%y);
}
//long long int ans[N<<2];
//int ls(int x){
//	return x<<1;
//}
//int rs(int x){
//	return x<<1|1;
//}
//void push_up(int x){
//	ans[x]=gcd(ans[ls(x)],ans[rs(x)]);
//}
//void build(int p,int l,int r){
//	if(l==r){
//		ans[p]=ca[l];
//		return ;
//	}
//	int mid=(l+r)>>1;
//	build(ls(p),l,mid);
//	build(rs(p),mid+1,r);
//	push_up(p);
//}
//long long int query(int nl,int nr,int l,int r,int p){
//	if(nl<=l&&r<=nr)return ans[p];
//	int mid=(l+r)>>1;
//	if(nl<=mid&&mid+1<=nr)return gcd(query(nl,nr,l,mid,ls(p)),query(nl,nr,mid+1,r,rs(p)));
//	if(nl<=mid)return query(nl,nr,l,mid,ls(p));
//	else return query(nl,nr,mid+1,r,rs(p));
//}
int Log[N];
long long int st[N][20];
void ST(){
	Log[0]=-1;
	for(int i=1;i<=n-1;i++)Log[i]=Log[i>>1]+1;
	for(int i=1;i<=n-1;i++)st[i][0]=ca[i];
	for(int j=1;(1<<j)<=n-1;j++){
		for(int i=1;i+(1<<j)-1<=n-1;i++){
			st[i][j]=gcd(st[i][j-1],st[i+(1<<(j-1))][j-1]);
		}
	}
}
long long int query(int l,int r){
	int k=Log[r-l+1];
	return gcd(st[l][k],st[r-(1<<k)+1][k]);
}
bool check(int x){
	if(x==n)return 0;
	for(int i=1;i+x-1<=n-1;i++){
		if(query(i,i+x-1)!=1)return 1;
	}
	return 0;
}
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			ca[i-1]=abs(a[i]-a[i-1]);
//			printf("%d ",ca[i-1]);
		}
//		printf("\n");
//		build(1,1,n-1);
		ST();
		int l=1,r=n-1,mid;
		while(l<r){
			mid=(l+r)>>1;
			if(check(mid))l=mid+1;
			else r=mid;
		}
		if(check(l+1))printf("%d\n",l+2);
		else if(check(l))printf("%d\n",l+1);
		else printf("%d\n",l);
	}
}