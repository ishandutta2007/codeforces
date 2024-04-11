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
const int N=2e5+10;
int n;char s[N];
int ban[N],t[200];
signed main(){
	int T=read();while(T--){
		scanf("%s",s+1),n=strlen(s+1);For(i,1,n)ban[i]=0;
		memset(t,0,sizeof t);
		For(c,'0','9'){
			int lst=0;For(i,1,n)if(!ban[i]&&s[i]==c)lst=i,t[s[i]]++;
			if(lst){
				For(i,1,lst-1)if(!ban[i]&&s[i]>s[lst])ban[i]=1,t[min(s[i]+1,(int)'9')]++;
			}
		}
		For(c,'0','9')while(t[c]--)putchar(c);puts("");
	}
	return 0;
}