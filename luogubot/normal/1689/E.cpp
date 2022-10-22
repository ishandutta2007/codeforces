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
const int N=2e3+10;
int n,a[N];
#define lowbit(x) (x&-x)
vector<int> g[33];
int ok[N];
void dfs(int u){ok[u]=0;for(int v:g[u])if(ok[v])dfs(v);}
bool check(){
	For(i,0,30)ok[i]=0,g[i].clear();
	For(i,1,n){
		int x=a[i],lst=-1;
		while(x){
			int v=__builtin_ctz(x);x^=lowbit(x);ok[v]=1;
			if(~lst)g[v].push_back(lst),g[lst].push_back(v);lst=v;
		}
	}Rof(i,30,0)if(ok[i]){dfs(i);break;}
	For(i,0,30)if(ok[i])return 0;return 1;
}
#define out(x) cout<<x<<endl;For(i,1,n)printf("%d ",a[i]);puts("");
signed main(){
	int T=read();while(T--){
		int c=0,ans=0;
		For(i,1,n=read())if(!(a[i]=read()))a[i]++,ans++;
		if(check()){out(ans);continue;}int mx=0; 
		For(i,1,n)mx=max(mx,lowbit(a[i]));
		int fl=0;For(i,1,n){
			if(a[i]>1){
				a[i]--;if(check()){out(ans+1);fl=1;break;}a[i]++;
			}
			a[i]++;if(check()){out(ans+1);fl=1;break;}a[i]--;
		}if(fl)continue;
		For(i,1,n)if(lowbit(a[i])==mx){a[i]--;break;}
		For(i,1,n)if(lowbit(a[i])==mx){a[i]++;break;}
		out(ans+2);
	}
	return 0;
}