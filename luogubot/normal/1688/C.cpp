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
const int N=2e5+10;
char s[N];
int ans[50];
signed main(){
	int T=read();while(T--){
		memset(ans,0,sizeof ans);
		int n=read();For(i,1,2*n+1){
			scanf("%s",s);For(i,0,strlen(s)-1)ans[s[i]-'a']^=1; 
		}For(i,0,25)if(ans[i]){putchar(i+'a');break;}
		puts("");
	}
	return 0;
}