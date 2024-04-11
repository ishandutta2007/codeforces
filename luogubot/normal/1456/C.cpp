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
const int N=5e5+10;
int n,k,c[N];priority_queue<int> q;
signed main(){
	n=read(),k=read();For(i,1,n)c[i]=read();sort(c+1,c+1+n),reverse(c+1,c+1+n);
	For(i,1,k+1)q.push(0);int ans=0;For(i,1,n){
		int now=q.top();q.pop();ans+=now,now+=c[i],q.push(now);
	}cout<<ans<<endl;
	return 0;
}