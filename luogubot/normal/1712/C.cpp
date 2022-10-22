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
const int N=1e5+10;
int n,a[N],mp[N];
int fi[N];
signed main(){
	int T=read();while(T--){
		int idx=0;n=read();
		For(i,1,n)mp[i]=0;
		For(i,1,n){
			int x=read();fi[i]=0;
			if(!mp[x])fi[i]=1,mp[x]=1,idx++;
			a[i]=x;
		}int ans=idx,now=0,del=0;
		For(i,1,n)mp[i]=0;
		Rof(i,n,1){
			if(i<n&&a[i]>a[i+1])break;
			if(!mp[a[i]])mp[a[i]]=1,now++,del++;
			if(fi[i])now--;
			if(!now)ans=idx-del;
		}cout<<ans<<endl;
	}
	return 0;
}