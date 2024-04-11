#include<bits/stdc++.h>
using namespace std;
//static char buf[1000000],*p1=buf,*p2=buf;
//#define getchar() p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++
#define pi pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define ls (rt<<1)
#define rs (rt<<1|1)
#define mid (l+r>>1)
#define lowbit(x) (x&-x)
const int maxn=5e5+5,M=34005,mod=1e9+7,mod2=998244353;
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
int n,m,a[maxn];
struct Hash{
	int x,y;
	Hash(int a=0,int b=0){x=a,y=b;}
	Hash operator + (const Hash &a)const{return Hash((x+a.x)%mod,(y+a.y)%mod2);}
	Hash operator - (const Hash &a)const{return Hash((x-a.x+mod)%mod,(y-a.y+mod2)%mod2);}
	Hash operator * (const Hash &a)const{return Hash(1ll*x*a.x%mod,1ll*y*a.y%mod2);}
	bool operator ==(const Hash &a)const{return x==a.x&&y==a.y;}
}base,fac[maxn];
struct BIT{
	Hash c[maxn];
	void add(int x,Hash num){for(int i=x;i<=n;i+=lowbit(i))c[i]=c[i]+num;}
	Hash query(int x){Hash res;for(int i=x;i;i-=lowbit(i))res=res+c[i];return res;}
}T1,T2;
bool check(int l,int r,int l2){
	Hash a=T1.query(r)-T1.query(l-1);
	Hash b=T2.query(l2)-T2.query(r-1);
	b=b*fac[r];a=a*fac[n-r+1];
	//cout<<a.x<<" "<<b.x<<" "<<r<<" "<<n-r+1<<endl;
	if(a==b)return 0;return 1;
}
signed main(){
	//freopen("1.in","r",stdin);
	//freopen(".out","w",stdout);
	n=read();fac[0]=Hash(1,1);base=Hash(197,233);
	for(int i=1;i<=n;i++)a[i]=read(),fac[i]=fac[i-1]*base;
	for(int i=1;i<=n;i++){
		T1.add(a[i],fac[a[i]-1]);T2.add(a[i],fac[n-a[i]]);
		int z=min(a[i]-1,n-a[i]);
		if(check(a[i]-z,a[i],a[i]+z)){puts("YES");exit(0);}
	}puts("NO");
 	return 0;
}