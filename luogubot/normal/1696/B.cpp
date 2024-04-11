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
int n,a[N];
signed main(){
	int TTT=read();while(TTT--){
		n=read();For(i,1,n)a[i]=read();
		int fl=0;
		For(i,1,n)if(a[i])fl=1;
		if(!fl){puts("0");continue;}
		int fl2=0;
		For(i,1,n)if(a[i]){
			int r=i;while(r<n&&a[r+1])r++;
			For(j,r+1,n)if(a[j])fl2=1;
			break;
		}puts(fl2?"2":"1");
	}
	return 0;
}