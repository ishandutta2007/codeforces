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
const int N=1e6+10,p=998244353;
int n,a[N],k,v[N];
signed main(){
	srand(time(NULL));
	int TTT=read();while(TTT--){
		n=read(),k=read();For(i,1,n)a[i]=read();
		int fl=1,ans=1;Rof(i,n,n-k+1)if(a[i]>0)fl=0;
		For(i,1,k)(ans*=i)%=p;For(i,k+1,n){
			v[i]=a[i-k];if(v[i]==0)(ans*=(k+1))%=p;
			else if(v[i]==-1)(ans*=i)%=p;
			if(v[i]>=i)fl=0;
		}cout<<ans*fl<<endl;
	}
	return 0;
}