#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a),i##END=(b);i<=i##END;i++)
#define Rof(i,b,a) for(int i=(b),i##END=(a);i>=i##END;i--)
#define go(u) for(int i=head[u];i;i=nxt[i])
#define endout fflush(stdout)
using namespace std;
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*f;
}
const int N=2e3+10;
int n,dep[N],c,a[N];
#define pi pair<int,int>
#define fi first
#define se second
vector<pi> g;
signed main(){
	n=read(),puts("? 1"),endout;
	For(i,1,n)dep[i]=read(),c+=dep[i]&1;
	if(c<n/2){
		// 
		For(i,1,n)if(dep[i]&1){
			printf("? %d\n",i),endout;
			For(j,1,n)a[j]=read();
			For(j,1,n)if(a[j]==1&&((dep[j]==dep[i]+1)||(dep[j]==dep[i]-1)))g.push_back(pi(i,j));
		}
	}else{
		// 
		For(i,1,n)if(!(dep[i]&1)){
			if(i!=1){
				printf("? %d\n",i),endout;
				For(j,1,n)a[j]=read();
			}else For(j,1,n)a[j]=dep[j];
			For(j,1,n)if(a[j]==1&&((dep[j]==dep[i]+1)||(dep[j]==dep[i]-1)))g.push_back(pi(i,j));
		}
	}puts("!");for(auto v:g)printf("%d %d\n",v.fi,v.se);endout;
	return 0;
}