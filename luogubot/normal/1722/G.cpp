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
const int N=2e5+10;
int n,a[N];
signed main(){
	int T=read();while(T--){
		n=read();
		For(i,1,n-1)a[i]=i;
		int A=0,B=0;For(i,1,n-1)if(i%2==1)A^=a[i];else B^=a[i];
		if(A==B)a[n]=0;
		else{
			a[n]=A^B^(1<<25);int fl=0;
			For(i,1,n-1)if(a[i]!=(A^B)){a[i]^=(1<<25),fl=1;break;}
			if(!fl){
				a[n]^=(1<<24),a[n%2==1?1:2]^=(1<<25)^(1<<24);
			}
		}
		A=0,B=0;For(i,1,n)if(i%2==1)A^=a[i];else B^=a[i];
		assert(A==B);For(i,1,n)cout<<a[i]<<" ";puts("");
	}
	return 0;
}