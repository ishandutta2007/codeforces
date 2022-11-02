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
#define int __int128
const int maxn=2e5+5,M=34005,mod=(1ll<<32);
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
    while(top) putchar(a[--top]+48);puts("");
}
int n,m,p,q,a[maxn],b[maxn],ans=0,sum=0,g[maxn],c[maxn],tot=0;
int C(int x,int y){
	for(int i=1;i<=y;i++)a[i]=i,b[i]=x-i+1;tot=0;
	for(int i=1;i<=y;i++){
		for(int j=2;j<=a[i];j++)
			if(a[i]%j==0){
				while(a[i]%j==0)a[i]/=j,c[++tot]=j;
			}	
	}
	for(int i=1;i<=tot;i++)
		for(int j=1;j<=y;j++)
			if(b[j]%c[i]==0){b[j]/=c[i];break;}
	int res=1;
	for(int i=1;i<=y;i++)res=res*b[i]%mod;
	return res;
}
signed main(){
	//freopen("1.in","r",stdin);
	//freopen(".out","w",stdout);
	n=read(),p=read(),q=read();sum=0;
	for(int i=1;i<=min(n-1,p);i++)g[i]=C(n,i);g[0]=1;
	//print(C(100,100));
	for(int i=1;i<=q;i++){
		sum=0;int o=1;
		for(int j=0;j<=min(n-1,p);j++){
			sum=(sum+g[j]*o%mod)%mod;o=o*i%mod;
		}sum=sum*i%mod;
		ans=ans^sum;
	}
	print(ans);
 	return 0;
}