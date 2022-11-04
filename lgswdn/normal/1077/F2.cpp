#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(register int i=a;i<=b;i++)
using namespace std;
const int N=5009;

int n,k,m,a[N];

namespace f1 {
	int f[209][209];
	void main() {
		memset(f,128,sizeof(f));
		rep(i,0,k-1) f[i][0]=0;
		rep(j,1,m) rep(i,1,n) {
			rep(p,max(1ll,i-k+1),i)
				f[i][j]=max(f[i][j],f[p-1][j-1]+a[p]);
		}
		printf("%lld\n",max(-1ll,f[n][m]));
	}
}

namespace f2 {
	int f[N][N];
	struct monoque {
    	int q[N],size,l,r,g[N];
    	monoque(int x=0) {l=r=1;}
    	void maintain(int x) {
        	while(l<r&&x-q[l]>size) l++;
    	}
    	void clear() {l=r=1;}
    	void push(int x,int gg) {
    	    g[x]=gg;
     	    while(l<r&&g[x]>g[q[r-1]]) r--;
    	    q[r++]=x;
    	}
    	int max() {return g[q[l]];}
	}q;
	void main() {
		memset(f,128,sizeof(f));
		q.size=k-1;
		rep(i,0,k-1) f[i][0]=0;
		rep(j,1,m) {
			q.clear();
			q.push(0,f[0][j-1]);
			rep(i,1,n) {
				q.push(i,f[i-1][j-1]+a[i]);
				q.maintain(i);
				f[i][j]=q.max();
			}
		}
		printf("%lld\n",max(-1ll,f[n][m]));
	}
}

signed main() {
	scanf("%lld%lld%lld",&n,&k,&m);
	rep(i,1,n) scanf("%lld",&a[i]);
	if(n<=200) f1::main();
	else f2::main();
	return 0;
}