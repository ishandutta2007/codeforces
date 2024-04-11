#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a),i##END=(b);i<=i##END;i++)
#define Rof(i,b,a) for(int i=(b),i##END=(a);i>=i##END;i--)
#define go(u) for(int i=head[u];i;i=nxt[i])
//#define int long long
using namespace std;
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*f;
}
const int N=1e3+10,M=1e5+10;
int v[N][N],n,m,t[N][N];
char s[M];
signed main(){
	int T=read();while(T--){
		n=read(),m=read();
		For(i,1,n)For(j,1,n)v[i][j]=read();
		int a=0,b=0,c=0,na=1,nb=2,nc=3;
		scanf("%s",s+1);For(i,1,m){
			if(s[i]=='U')a--;
			if(s[i]=='D')a++;
			if(s[i]=='L')b--;
			if(s[i]=='R')b++;
			if(s[i]=='I')swap(b,c),swap(nb,nc);
			if(s[i]=='C')swap(a,c),swap(na,nc);
		}a=(a%n+n)%n,b=(b%n+n)%n,c=(c%n+n)%n;
		For(x,1,n)For(y,1,n){
			int i=x,j=y,k=v[x][y];
			int I,J,K;
			if(na==1)I=i;if(na==2)I=j;if(na==3)I=k;
			if(nb==1)J=i;if(nb==2)J=j;if(nb==3)J=k;
			if(nc==1)K=i;if(nc==2)K=j;if(nc==3)K=k;
			i=I,j=J,k=K;
			i=(i+a-1)%n+1,j=(j+b-1)%n+1,k=(k+c-1)%n+1;
			t[i][j]=k;
		}For(i,1,n)For(j,1,n)printf("%d%c",t[i][j]," \n"[j==n]);
//		puts("");
	}
	return 0;
}