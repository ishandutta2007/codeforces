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
int a[N];
int n,m,k;
bool check(){
	int fl=0,ok=0,now=0;
	For(i,1,k)if(a[i]/n>1){
		if(a[i]/n>2)fl=1;
		if(m-now>1)now+=a[i]/n;
		else ok=1;
		ok|=now>=m;
	}return ok&&(now>=m||fl);
}
signed main(){
	int T=read();while(T--){
		n=read(),m=read(),k=read();
		For(i,1,k)a[i]=read();
		int fl=check();
		swap(n,m);
		fl|=check();
		puts(fl?"Yes":"No");
	}
	return 0;
}