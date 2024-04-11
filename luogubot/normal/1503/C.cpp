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
bool ST;
const int N=1e5+10;
int n,ans,f[N];
struct node{
	int a,c;
	bool operator < (const node &x) const {
		return a<x.a;
	}
}a[N];
bool ED;
signed main(){
	For(i,1,n=read())a[i].a=read(),ans+=a[i].c=read();
	sort(a+1,a+1+n);int mx=0;For(i,1,n-1){
		mx=max(mx,a[i].a+a[i].c);
		if(mx<a[i+1].a)ans+=a[i+1].a-mx;
	}cout<<ans<<endl;
	return 0;
}