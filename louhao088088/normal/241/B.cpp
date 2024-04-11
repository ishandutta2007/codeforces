// Problem: CF241B Friends
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF241B
// Memory Limit: 250 MB
// Time Limit: 6000 ms
// 2022-04-28 11:42:02
// Author : louhao088
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
//static char buf[1000000],*p1=buf,*p2=buf;
//#define getchar() p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++
#define pi pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define lowbit(x) (x&-x)
#define int long long
const int maxn=5e4+5,M=31,mod=1e9+7;
inline int read(){
	char ch=getchar();bool f=0;int x=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f==1)x=-x;return x;
}
inline void print(int x){
    static int a[55];int top=0;
    if(x<0) putchar('-'),x=-x;
    do{a[top++]=x%10,x/=10;}while(x);
    while(top) putchar(a[--top]+48);
}
signed sum[maxn*18][32][2],cnt[maxn*20],ls[maxn*20],rs[maxn*20],Rt;
int n,m,x,ans,num,tot=0,a[maxn],gg=0;
void ins(signed &rt,int num,int x){
	if(!rt)rt=++tot;cnt[rt]++;
	if(!x)return;
	int z=((1ll<<(x-1))&num);
	if(z)sum[rt][x][1]++,ins(rs[rt],num,x-1);
	else sum[rt][x][0]++,ins(ls[rt],num,x-1);
	for(int i=1;i<x;i++)sum[rt][i][0]=sum[ls[rt]][i][0]+sum[rs[rt]][i][0],
	sum[rt][i][1]=sum[ls[rt]][i][1]+sum[rs[rt]][i][1];
}
int query(int rt,int num,int y,int x){
	if(!rt)return 0;if(!x)return cnt[rt];
	int z1=((1ll<<(x-1))&num);int z2=((1ll<<(x-1))&y);
	if(z2){
		if(z1)return query(ls[rt],num,y,x-1);
		else return query(rs[rt],num,y,x-1);
	}
	if(!z1)return cnt[rs[rt]]+query(ls[rt],num,y,x-1);
	else return cnt[ls[rt]]+query(rs[rt],num,y,x-1);
}
int getx(int rt,int x,int y){
	int res=0;
	for(int i=1;i<x;i++){
		int z=((1ll<<(i-1))&y);
		res+=(1ll*((1ll<<(i-1))%mod)*sum[rt][i][!z])%mod,res=res%mod;
	}	
	return res;
}
int query2(int rt,int num,int y,int x){
	if(!rt)return 0;
	//cout<<y<<" "<<cnt[rt]<<" "<<x<<endl;
	if(!x)return y*cnt[rt];
	int z1=((1ll<<(x-1))&num);int z2=((1ll<<(x-1))&y);
//	cout<<rt<<" "<<num<<endl;
	if(z2){
		if(z1)return query2(ls[rt],num,y,x-1);
		else return query2(rs[rt],num,y,x-1);
	}
	int g=y-(y%(1ll<<x))+(1ll<<(x-1));g=g%mod;//cout<<g<<" "<<z1<<" "<<rs[rt]<<" "<<cnt[rt]<<" "<<x<<endl;
	if(!z1)return (cnt[rs[rt]]*g+getx(rs[rt],x,num)+query2(ls[rt],num,y,x-1))%mod;
	else return (cnt[ls[rt]]*g+getx(ls[rt],x,num)+query2(rs[rt],num,y,x-1))%mod;
}
int get(int x){
	int res=0;
	for(int i=1;i<=n;i++)res+=query(Rt,a[i],x,M);res=res/2;
	return res;
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++)ins(Rt,a[i],M);
	
	int l=0,r=(1<<30),x=0;
	while(l<=r){
		int mid=l+r>>1;
		if(get(mid)>=m)l=mid+1,x=mid;
		else r=mid-1;
	}
	for(int i=1;i<=n;i++){ans+=query2(Rt,a[i],x,M),ans=ans%mod;}ans=ans*(mod/2+1)%mod;
//	cout<<ans<<endl;
	ans=ans-(get(x)-m)*x;ans=ans%mod;ans=(ans+mod)%mod;
	cout<<ans;
 	return 0;
}