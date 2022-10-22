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
const int N=4e5+10;
int n,c[N],a[N];
signed main(){
	int T=read();while(T--){
		For(i,1,n=read())c[i]=read(),a[i]=1;int fl=1;
		For(i,1,n){
			if(fl==1&&!c[i])a[i]=0;else{
				c[i]-=a[i]*(i-1);
				a[i+c[i]]=0;
				fl=0;
			}
			printf("%lld%c",a[i]," \n"[i==n]);
		}
	}
	return 0;
}