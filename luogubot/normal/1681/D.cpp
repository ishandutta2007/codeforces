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
unordered_map<int,int> mp;
int n,x;queue<int> q;
int lg(int x){int c=0;while(x)c++,x/=10;return c;}
signed main(){
	int T=1;while(T--){
		mp.clear();n=read(),x=read();
		if(x==1){puts("-1");continue;}
		while(!q.empty())q.pop();mp[x]=1;
		int ans=0;
		q.push(x);while(!q.empty()){
			int x=q.front(),t=mp[x]+1;q.pop();
			int u=x;while(u){
				int y=x*(u%10);u/=10;
				if(!mp[y]){
					mp[y]=t,q.push(y);
					if(lg(y)==n){ans=t;break;}
				}
			}
			if(ans)break;
		}cout<<ans-1<<endl;
	}
	return 0;
}