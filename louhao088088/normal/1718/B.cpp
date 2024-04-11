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
const int maxn=5e5+5,M=34005;
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
int n,m,a[maxn],b[maxn],f[maxn],p,T,F;
void dfs(int x,int las){
	if(x==0){F=1;return;}
	if(F)return; 
	for(int i=1;i<=n;i++)
		if(a[i]>=f[x]&&i!=las)a[i]-=f[x],dfs(x-1,i),a[i]+=f[x];
}
void solve(){
	n=read();int s=0;F=0;
	for(int i=1;i<=n;i++)a[i]=read(),s+=a[i];int t=0,p=0;
	if(n>50){puts("NO");return;}
	for(int i=1;i<=50;i++){
		t+=f[i];if(t==s){p=i;break;} 
	}if(!p){puts("NO");return;}
	dfs(p,0);
	if(F)puts("YES");
	else puts("NO");
} 
signed main(){
	//freopen("1.in","r",stdin);
	//freopen(".out","w",stdout);
	T=read();f[1]=f[2]=1;
	for(int i=3;i<=50;i++)f[i]=f[i-1]+f[i-2];
	while(T--)solve();
 	return 0;
}