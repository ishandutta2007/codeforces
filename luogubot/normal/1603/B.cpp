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
		int x=read(),y=read(),n=-1;
		if(x==y)n=x;
		else if(x<y){
			int s=x;x=x*(y/x+1);
			if(x>y)x-=s;n=(x+y)/2;
		}
		else n=x+y;
		cout<<n<<endl;
		assert(n%x==y%n);
//		cout<<n%x<<" ! "<<y%n<<endl;
	}
	return 0;
}