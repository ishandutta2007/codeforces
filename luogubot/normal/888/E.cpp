#include<bits/stdc++.h>//ddsadaswww
#define For(i,a,b) for(int i=(a),i##END=(b);i<=i##END;i++)
#define Rof(i,b,a) for(int i=(b),i##END=(a);i>=i##END;i--)
#define go(u) for(int i=head[u];i;i=nxt[i])
#define rep(i,n) For(i,0,(n)-1)
using namespace std;
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*f;
}
const int N=50;
int n,a[N],p,ans;
set<int> s1,s2;
signed main(){
	n=read(),p=read();rep(i,n)a[i]=read();
	rep(S,(1<<n/2)){
		int s=0;rep(i,n/2)if(S>>i&1)(s+=a[i])%=p;s1.insert(s);
	}rep(S,(1<<(n+1)/2)){
		int s=0;rep(i,(n+1)/2)if(S>>i&1)(s+=a[i+n/2])%=p;s2.insert(s);
	}for(auto v:s1){
		auto it=s2.lower_bound(p-1-v);
		if(it!=s2.end())ans=max(ans,(v+*it)%p);
		if(it!=s2.begin())ans=max(ans,(v+*prev(it))%p);
	}cout<<ans<<endl;
	return 0;
}//sadsa