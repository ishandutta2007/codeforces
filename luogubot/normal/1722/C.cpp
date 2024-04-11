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
map<string,int> mp;
int a[3];
signed main(){
	int T=read();while(T--){
		mp.clear(),a[0]=a[1]=a[2]=0;
		int n=read();
		For(x,0,2)For(i,1,n){
			string s;cin>>s;mp[s]+=(1<<x);
		}for(auto it:mp){
			int v=it.second;
			if(v==1||v==2||v==4)a[__builtin_ctz(v)]+=3;
			else if(v==7);
			else{
				For(x,0,2)if(v>>x&1)a[x]++;
			}
		}For(x,0,2)cout<<a[x]<<" ";puts("");
	}
	return 0;
}