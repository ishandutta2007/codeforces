// LUOGU_RID: 90477872
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
const int maxn=1005,M=2e5+5,mod=998244353;
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
int Pow(int x,int y){int res=1;while(y){if(y&1)res=res*x%mod;x=x*x%mod;y=y/2;}return res;}
int n,m,x,y,tot=0,ans=0,a[maxn],b[maxn],c[maxn],C[maxn],g[maxn];
signed main(){
	//freopen("1.in","r",stdin);
	//freopen(".out","w",stdout);
	
	n=read();//cout<<"A";
	for(int i=1;i<=n;i++){
		a[i]=read(),b[i]=read();c[++tot]=a[i],c[++tot]=b[i]+1;
	}sort(c+1,c+tot+1);C[0]=g[0]=1;
	int un=unique(c+1,c+tot+1)-c-1;
	for(int i=1;i<=n;i++){
		a[i]=lower_bound(c+1,c+un+1,a[i])-c;
		b[i]=lower_bound(c+1,c+un+1,b[i]+1)-c;
	}
	for(int i=un;i>=2;i--){
		int L=c[i]-c[i-1];
		for(int j=1;j<=n;j++)C[j]=C[j-1]*(L+j-1)%mod*Pow(j,mod-2)%mod;
		for(int j=n;j>=1;j--)if(a[j]<=i-1&&i<=b[j]){
			for(int k=j-1,p=1;k>=0;k--,p++){
				g[j]=(g[j]+C[p]*g[k])%mod;
				if(a[k]>i-1||i>b[k])break;
			}
		}
	}int ans=g[n];
	for(int i=1;i<=n;i++)ans=ans*Pow(c[b[i]]-c[a[i]],mod-2)%mod;
	cout<<ans<<endl;
 	return 0;
}