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
signed main(){
	int T=read();while(T--){
		int a=read(),b=read(),c=read(),d=read(),k,l;a-=b;
		if(a>0){
			if(c<=d){printf("-1\n");continue;}
		}else{printf("%d\n",b);continue;}
		l=c-d,k=(a-1)/l+1;
		printf("%lld\n",b+k*c);
	}
	return 0;
}