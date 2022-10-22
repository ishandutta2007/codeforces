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
int n,q,a[N];
signed main(){
	int T=1;while(T--){
		n=read(),q=read();For(i,1,n)a[i]=read();sort(a+1,a+1+n);
		For(i,1,n)a[i]+=a[i-1];
		while(q--){
			int x=read(),y=read();
			cout<<a[n-x+y]-a[n-x]<<endl;
		}
	}
	return 0;
}