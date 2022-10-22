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
int n,a[N];
map<int,int> mp;
signed main(){
	int T=read();while(T--){
		For(i,1,n=read())a[i]=read();
		mp.clear();int fl=0;For(i,1,n){
			int x=((i+a[i])%n+n)%n;
			if(mp[x]){fl=1;break;}
			mp[x]=1;
		}puts(fl?"No":"Yes");
	}
	return 0;
}