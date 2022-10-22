#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a),i##END=(b);i<=i##END;i++)
#define Rof(i,b,a) for(int i=(b),i##END=(a);i>=i##END;i--)
#define go(u) for(int i=head[u];i;i=nxt[i])
using namespace std;
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*f;
}
const int N=1e6+10,lim=200;
int n;char s[N];
int SG[N],tmp[210];
signed main(){
	n=2000,SG[0]=SG[1]=0,SG[2]=1;For(i,3,n){
		memset(tmp,0,sizeof tmp);
		For(j,1,i-1)tmp[SG[i-j-1]^SG[j-1]]=1;
		For(j,0,lim)if(!tmp[j]){SG[i]=j;break;}
	}For(i,n+1,N-10)SG[i]=SG[i-34];
	int T=read();while(T--){
		n=read(),scanf("%s",s+1);
		int R=0,B=0;
		For(i,1,n)(s[i]=='R')?R++:B++;
		if(R^B)puts(R>B?"Alice":"Bob");
		else{
			int sg=0;
			for(int i=1,lpos=1;i<=n+1;i++)if(s[i]==s[i-1]||i>n)sg^=SG[i-lpos],lpos=i;
			puts(sg?"Alice":"Bob");
		}
	}
	return 0;
}