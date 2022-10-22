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
const int N=1e5+10;
int n;char s[N],t[N];
int a[200][200];
signed main(){
	int T=read();while(T--){
		n=read(),scanf("%s%s",s+1,t+1);
		For(i,1,n)a[s[i]][t[n-i+1]]++;int fl=1;
		if(n%2==0){
			For(x,'a','z')For(y,'a','z')while(a[x][y]){
				a[x][y]%=2;
				if(a[x][y]){
					a[x][y]--;
					if(a[y][x])a[y][x]--;
					else fl=0;
				}
			}
		}else{
			For(x,'a','z')For(y,'a','z')if(x!=y)while(a[x][y]){
				a[x][y]%=2;
				if(a[x][y]){
					a[x][y]--;
					if(a[y][x])a[y][x]--;
					else fl=0;
				}
			}int used=1;
			if(fl)For(x,'a','z')if(a[x][x]){
				a[x][x]%=2;
				if(a[x][x])used?used=0:fl=0;
			}
		}
		For(i,1,n)a[s[i]][t[n-i+1]]=0;
		puts(fl?"YES":"NO");
	}
	return 0;
}