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
const int N=1e5+10,p=1e9+7;
int phi[N],pr[N],st[N],cnt;
void get_phi(int n){
	phi[1]=1;
	for(int i=2;i<=n;i++){
		if(!st[i])phi[i]=i-1,pr[++cnt]=i;
		for(int j=1;j<=cnt&&i*pr[j]<=n;j++){
			st[i*pr[j]]=1;
			if(i%pr[j]==0){
				phi[i*pr[j]]=phi[i]*pr[j];
				break;
			}
			phi[i*pr[j]]=phi[i]*phi[pr[j]];
		}
	}
}
inline int lcm(int a,int b){return a/__gcd(a,b)*b%p;}
signed main(){
	get_phi(N-10);
	int n=read(),ans=0;
	For(d,1,n-1){
		for(int x=2*d;x<=n;x+=d){
			(ans+=phi[x/d]%p*lcm(n-x,d))%=p;
		}
	}cout<<ans<<endl;
	return 0;
}