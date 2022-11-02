#include<bits/stdc++.h>
using namespace std;
#define pi pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define ls (x<<1)
#define rs (x<<1|1)
#define mid ((l+r)>>1)
#define lowbit(x) (x&-x)
#define int long long
const int maxn=2e5+5,M=34005;
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
int n,a[maxn],s[maxn],st[maxn][22],lg[maxn],ans=0;
int Max(int x,int y){if(a[x]<a[y])return y;return x;}
int get(int l,int r){
	int x=lg[r-l+1];
	return Max(st[l][x],st[r-(1<<x)+1][x]);
}
signed main(){
	//freopen("1.in","r",stdin);
	//freopen(".out","w",stdout);
	n=read();lg[0]=-1;
	for(int i=1;i<=n;i++)lg[i]=lg[i/2]+1;
	for(int i=1;i<n;i++)a[i]=read(),st[i][0]=i;s[n-1]=1;ans=1;st[n][0]=n;
	for(int i=1;(1<<i)<=n;i++)
		for(int j=1;j+(1<<i)<=n+1;j++)
			st[j][i]=Max(st[j][i-1],st[j+(1<<(i-1))][i-1]);
	for(int i=n-2;i>=1;i--){
		int u=get(i+1,a[i]);
		s[i]=s[u]+n+u-i-a[i];//cout<<s[i]<<" "<<u<<" "<<i+1<<" "<<a[i]<<endl;
		ans+=s[i];
	}cout<<ans<<endl;
 	return 0;
}