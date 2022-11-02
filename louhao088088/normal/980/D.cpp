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
const int maxn=5005,M=2e5+5;
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
int n,m,a[maxn],b[maxn],s[maxn],ans[maxn];
signed main(){
	//freopen("1.in","r",stdin);
	//freopen(".out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++){if(a[i]==0)continue;
		for(int j=1;j<=i;j++){
			int x=a[i]*a[j];if(x<=0)continue;int y=sqrt(x);
			if(y*y==x){b[i]=j;break;}
		}
	}
	for(int i=1;i<=n;i++){
		memset(s,0,sizeof s);int u=0;
		for(int j=i;j<=n;j++){
			
			s[b[j]]++;if(s[b[j]]==1&&a[j]!=0)u++;
			ans[max(u,1ll)]++;
		}
	}
	for(int i=1;i<=n;i++)printf("%lld ",ans[i]);
 	return 0;
}