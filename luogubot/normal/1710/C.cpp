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
const int N=2e5+10,p=998244353;
int n,f[N][8][8];char s[N];
bool _1(int i){return s[i]=='1';}
void dp(){
	For(i,0,n-1)For(j,0,7)For(k,0,7)if(f[i][j][k]){
		int sta=0;For(l,0,2)if(!(k>>l&1)||_1(i+1))sta|=1<<l;
		For(S,0,7)if((sta&S)==S){
			int h=0;if(_1(i+1))h=S;else h=7;
			if(S==0||S==7){
				(f[i+1][j][k&h]+=f[i][j][k])%=p;
			}else if(S==1||S==6){
				(f[i+1][j|(1<<0)][k&h]+=f[i][j][k])%=p;
			}else if(S==2||S==5){
				(f[i+1][j|(1<<1)][k&h]+=f[i][j][k])%=p;
			}else if(S==3||S==4){
				(f[i+1][j|(1<<2)][k&h]+=f[i][j][k])%=p;
			}else puts("NO");
		}
	}int ans=0;For(i,0,7)(ans+=f[n][7][i])%=p;cout<<ans<<endl;
}
signed main(){
	scanf("%s",s+1),n=strlen(s+1);
	f[0][0][7]=1,dp();
	return 0;
}