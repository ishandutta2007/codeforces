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
const int N=3e5+10;
int n,a[N],s[N],sum;
vector<int> g[70];
signed main(){
	For(i,1,n=read())sum+=a[i]=read(),s[i]=read(),g[__builtin_ctzll(s[i])].push_back(i);
	if(sum<0){sum=-sum;For(i,1,n)a[i]=-a[i];}int S=0;
	Rof(j,61,0){
		int t=0;for(auto i:g[j]){
			if(__builtin_popcountll(s[i]&S)&1)a[i]=-a[i];
			t+=a[i];
		}if(t>0)S^=(1ll<<j);
	}cout<<S<<endl;
	return 0;
}//fdadas