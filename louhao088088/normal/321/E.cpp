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
const int maxn=4e3+5,M=34005;
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
int n,m,k,f[maxn][805],s[maxn][maxn];
int get(int i,int j){return (s[j][j]-s[j][i-1]-s[i-1][j]+s[i-1][i-1])/2;}
void solve(int x,int l,int r,int ql,int qr){
	if(l>r)return;
	f[mid][x]=1e9;int qmid=ql;
	for(int i=ql;i<=min(mid,qr);i++)
		if(f[i][x-1]+get(i+1,mid)<f[mid][x]){
			f[mid][x]=f[i][x-1]+get(i+1,mid);qmid=i;
		}
	if(l==r)return;
	solve(x,l,mid-1,ql,qmid),solve(x,mid+1,r,qmid,qr);
}
signed main(){
	//freopen("1.in","r",stdin);
	//freopen(".out","w",stdout);
	n=read(),k=read();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)s[i][j]=read(),s[i][j]=s[i][j]+s[i-1][j]+s[i][j-1]-s[i-1][j-1];
	for(int i=1;i<=n;i++)f[i][1]=get(1,i);
	for(int i=2;i<=k;i++)solve(i,1,n,1,n);
	cout<<f[n][k];
 	return 0;
}