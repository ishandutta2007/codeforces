#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a),i##END=(b);i<=i##END;i++)
#define Rof(i,b,a) for(int i=(b),i##END=(a);i>=i##END;i--)
#define go(u) for(int i=head[u];i;i=nxt[i])
#define int long long
using namespace std;
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*f;
}
const int N=5e5+10,inf=1e18;
int n,s[N],a[N],f[N],c1[N],c2[N],c3[N];
#define lowbit(x) (x&-x)
inline void gmax(int &a,int b){(a<b)&&(a=b);}
void add1(int u,int v){
	for(int i=u;i<=n+1;i+=lowbit(i))gmax(c1[i],v);
}
int ask1(int u,int s=-inf){
	for(int i=u;i;i-=lowbit(i))gmax(s,c1[i]);return s;
}
void add2(int u,int v){
	for(int i=u;i;i-=lowbit(i))gmax(c2[i],v);
}
int ask2(int u,int s=-inf){
	for(int i=u;i<=n+1;i+=lowbit(i))gmax(s,c2[i]);return s;
}
signed main(){
	int T=read();while(T--){
		n=read(); 
		For(i,1,n+1)c1[i]=c2[i]=c3[i]=-inf;a[0]=s[0]=0;
		For(i,1,n)a[i]=s[i]=s[i-1]+read();
		sort(a,a+1+n);For(i,0,n)s[i]=lower_bound(a,a+1+n,s[i])-a+1;
		//s[l]<s[r]:f[l]-l+r
		//s[l]>s[r]:f[l]+l-r
		//s[l]=s[r]:f[l]
		For(i,0,n){
			if(i)f[i]=max({c3[s[i]],ask1(s[i]-1)+i,ask2(s[i]+1)-i});
			gmax(c3[s[i]],f[i]),add1(s[i],f[i]-i),add2(s[i],f[i]+i);
		}printf("%lld\n",f[n]);
	}
	return 0;
}