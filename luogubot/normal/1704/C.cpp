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
int n,m,a[N],b[N];
signed main(){
	int T=read();while(T--){
		n=read(),m=read();For(i,1,m)a[i]=read();sort(a+1,a+1+m);
		int k=0;For(i,1,m-1)b[++k]=a[i+1]-a[i]-1;b[++k]=(a[1]+n-a[m]-1)%n;
		sort(b+1,b+1+k),reverse(b+1,b+1+k);int ans=n,used=0; 
		For(i,1,k){
//			printf("[%lld] ",b[i]);
			if(b[i]-used<=0)break;
			if(b[i]-used<=2)ans--,used+=2;
			else ans-=b[i]-used-1,used+=4;
		}cout<<ans<<endl;
	}
	return 0;
}