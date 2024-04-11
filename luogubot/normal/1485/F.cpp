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
const int N=2e5+10,p=1e9+7;
int n,b[N];
map<int,int> F;
int addtag,sum;
void add(int x,int v){
	(F[x-addtag]+=v)%=p,(sum+=v)%=p;
}
int val(int x){return F[x-addtag];}
signed main(){
	int T=read();while(T--){
		addtag=0;For(i,1,n=read())b[i]=read();
		F.clear(),F[0]=sum=1;
		For(i,1,n){
			int del=val(0);
			addtag+=b[i];
			add(b[i],(sum-del+p)%p);
		}printf("%lld\n",sum);
	}
	return 0;
}