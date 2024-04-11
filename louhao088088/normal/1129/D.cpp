// LUOGU_RID: 91694935
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
#define int long long
const int maxn=1e5+5,M=2e5+5,mod=998244353,B=405;
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
int n,m,k,f[maxn],x,y,id[maxn],t,ans=0,tag[B],b[B],c[maxn];
int a[maxn],pre[maxn],p2[maxn],L[maxn],R[maxn],s[B][B];
void push(int x){
	int mn=1e9;memset(s[x],0,sizeof s[x]);
	for(int i=L[x];i<=R[x];i++)c[i]+=tag[x],mn=min(mn,c[i]);
	b[x]=mn;tag[x]=0;
	for(int i=L[x];i<=R[x];i++)s[x][c[i]-b[x]]+=f[i];
	for(int i=1;i<=t;i++)s[x][i]=s[x][i-1]+s[x][i];
}
void add(int l,int r,int x){
	if(id[l]==id[r]){for(int i=l;i<=r;i++){c[i]+=x;}push(id[l]);return;}
	for(int i=l;i<=R[id[l]];i++){c[i]+=x;}push(id[l]);
	for(int i=L[id[r]];i<=r;i++){c[i]+=x;}push(id[r]);
	for(int i=id[l]+1;i<id[r];i++)tag[i]+=x;
}
signed main(){
	//freopen("1.in","r",stdin);
	//freopen(".out","w",stdout);
	n=read();k=read();t=sqrt(n);
	R[0]=-1;
	for(int i=0;i<=n;i++)id[i]=i/t+1;
	for(int i=1;i<=id[n];i++)L[i]=R[i-1]+1,R[i]=min(n,i*t-1);
	f[0]=1;add(0,0,0);
	for(int i=1;i<=n;i++){
		a[i]=read();
		if(pre[a[i]])add(p2[a[i]],pre[a[i]]-1,-1);
		p2[a[i]]=pre[a[i]];pre[a[i]]=i;add(p2[a[i]],pre[a[i]]-1,1);
		ans=0;
		for(int j=1;j<=id[i-1];j++){
			int x=k-b[j]-tag[j];
			if(x<0)continue;
			if(x>t)ans+=s[j][t];
			else ans+=s[j][x];
			ans%=mod;
		}f[i]=ans;
	}
	cout<<f[n]<<endl;
	
 	return 0;
}