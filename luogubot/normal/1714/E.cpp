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
int n,a[N],b[N];
signed main(){
	int T=read();while(T--){
		int fl=0;
		For(i,1,n=read()){
			a[i]=read();
			if(a[i]%10==5)a[i]+=5;
			if(a[i]%10==0)fl|=1;
			else fl|=2;
		}
		if(fl==3){puts("NO");continue;}
		if(fl==1){
			int ok=1;
			For(i,2,n)ok&=a[i]==a[1];
			puts(ok?"YES":"NO");
			continue;
		}int ot=0;
		for(int x:{2,4,6,8}){
			For(i,1,n)b[i]=a[i];
			For(i,1,n)while(b[i]%10!=x)b[i]+=b[i]%10;
			int ok=1;
			For(i,2,n){
				int d=b[i]-b[1];
				d=(d%20+20)%20;
				ok&=(!d);
			}
			if(ok){puts("YES"),ot=1;break;}
		}if(!ot)puts("NO");
	}
	return 0;
}