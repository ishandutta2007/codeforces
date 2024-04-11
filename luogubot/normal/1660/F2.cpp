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
const int N=4e5+10,inf=1e18;
int n,s[N],c[3][N];
#define lowbit(x) (x&-x)
inline void gmax(int &a,int b){(a<b)&&(a=b);}
void add(int* c,int u,int v){
	for(int i=u;i;i-=lowbit(i))c[i]+=v;
}
int ask(int* c,int u,int s=0){
	for(int i=u;i<=2*n+1;i+=lowbit(i))s+=c[i];return s;
}char S[N];
signed main(){
	int T=read();while(T--){
		n=read(),scanf("%s",S+1);
		s[0]=0; 
		For(i,1,n)s[i]=(s[i-1]+((S[i]=='+')?1:-1));
//		For(i,1,n)printf("a[%d] = %d\n",i,s[i]);
		For(j,0,2)For(i,1,2*n+1)c[j][i]=0;
		int ans=0;
		For(i,0,n){
			s[i]+=n+1;
			ans+=ask(c[(s[i]%3+3)%3],s[i]),add(c[(s[i]%3+3)%3],s[i],1);
		}printf("%lld\n",ans);
	}
	return 0;
}