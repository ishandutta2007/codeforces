#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a),i##END=(b);i<=i##END;i++)
#define Rof(i,b,a) for(int i=(b),i##END=(a);i>=i##END;i--)
#define go(u) for(int i=head[u];i;i=nxt[i])
#define ll long long
using namespace std;
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*f;
}
const int N=1e6+10;
int n,ban[N],ok[N];char s[N];
signed main(){
	int T=read();while(T--){
		n=read(),scanf("%s",s+1);ll ans=0;
		For(i,1,n)ban[i]=ok[i]=0;For(i,1,n)if(s[i]=='0'){
			For(j,1,n/i){
				if(!ban[i*j]&&!ok[i*j]){
					if(s[i*j]=='0'){if(!ok[i*j])ans+=i,ok[i*j]=1;}
					else break;
				}
			}
		}cout<<ans<<endl;
	}
	return 0;
}