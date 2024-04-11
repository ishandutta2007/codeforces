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
signed main(){
	int T=read();while(T--){
		string a,b;int n=read();cin>>a>>b;int fl=1;
		For(i,0,n-1){
			if(a[i]=='G')a[i]='B';
			if(b[i]=='G')b[i]='B';
			fl&=(a[i]==b[i]);
		}puts(fl?"YES":"NO");
	}
	return 0;
}