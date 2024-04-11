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
const int N=1e5+10;
int n,a[N],d,m,b[N];
#define pi pair<int,int>
#define fi first
#define se second
pi c[N];
signed main(){
	int TTT=read();while(TTT--){
		n=read(),d=read();
		For(i,1,n){
			a[i]=read();
			int len=1;
			while(a[i]%d==0)a[i]/=d,len*=d;
			c[i]=pi(a[i],len);
		}int j=1,fl=1;
		For(i,1,m=read()){
			b[i]=read();
			if(!fl)continue;
			int len=1;
			while(b[i]%d==0)b[i]/=d,len*=d;
			while(len&&j<=n&&c[j].fi==b[i]){
				if(len<c[j].se){c[j].se-=len;len=0;break;}
				else len-=c[j].se,j++;
			}if(len)fl=0;
		}fl&=(j==n+1);
		puts(fl?"Yes":"No");
	}
	return 0;
}