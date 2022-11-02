// LUOGU_RID: 90781909
#include<bits/stdc++.h>
using namespace std;
#define pi pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define ls (rt<<1)
#define rs (rt<<1|1)
#define mid ((l+r)>>1)
#define lowbit(x) (x&-x)
const int maxn=2e5+5,M=2e5+5,mod=998244353;
inline int read(){
	char ch=getchar();bool f=0;int x=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f==1){x=-x;}return x;
}
void print(int x){
    static int a[55];int top=0;
    if(x<0) putchar('-'),x=-x;
    do{a[top++]=x%10,x/=10;}while(x);
    while(top) putchar(a[--top]+48);
}
int n,m,x,y,z,a[maxn],id[maxn],t,op,s[maxn],p[maxn],L[maxn],R[maxn];
pi ans;
void change(int x,int y){
	a[x]=y;
	int l=L[id[x]],r=R[id[x]];//if(id[x]==id[n])return;
	for(int i=x;i>=l;i--){
		if(i+a[i]>r){
			if(i+a[i]>n)p[i]=i,s[i]=1;
			else p[i]=i+a[i],s[i]=1;
		}
		else p[i]=p[i+a[i]],s[i]=s[i+a[i]]+1;
	}
}
pi query(int x){
	int res=0,g=x;
	for(int i=x;i<=n;i=p[i]){
		res+=s[i];g=p[i];
		if(id[g]==id[i]&&i!=g)res--;
		if(p[i]==i)break;
	}
	return mp(g,res);
}
signed main(){
	//freopen("1.in","r",stdin);
	//freopen(".out","w",stdout);
	
	n=read(),m=read();t=sqrt(n);
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++)id[i]=(i-1)/t+1;
	for(int i=1;i<=id[n];i++)L[i]=R[i-1]+1,R[i]=min(n,i*t);
	for(int i=n;i>=1;i--){
		int r=R[id[i]];
		if(i+a[i]>r){s[i]=1;
			if(i+a[i]>n)p[i]=i;
			else p[i]=i+a[i];
		}else p[i]=p[i+a[i]],s[i]=s[i+a[i]]+1;
	}
	for(int i=1;i<=m;i++){
		op=read();
		if(op==1)x=read(),ans=query(x),printf("%d %d\n",ans.fi,ans.se);
		else x=read(),y=read(),change(x,y);
	}
 	return 0;
}