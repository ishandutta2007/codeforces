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
char s[N],t[N];string ta,tb;
int n;vector<int> g[3]; 
signed main(){
	int T=read();while(T--){
		n=read();scanf("%s%s",s+1,t+1);
		For(i,0,2)g[i].clear();ta="",tb="";
		For(i,1,n)g[s[i]-'a'].push_back(i);
		For(i,1,n)if(s[i]!='b')ta+=s[i];
		For(i,1,n)if(t[i]!='b')tb+=t[i];
		if(ta==tb){
			int fl=1,ca=0,cc=0;
			For(i,1,n){
				if(t[i]=='a')fl&=(g[0][ca++]<=i);
				if(t[i]=='c')fl&=(g[2][cc++]>=i);
			}puts(fl?"YES":"NO");
		}else puts("NO");
	}
	return 0;
}