#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define SZ(x) ((int)x.size()-1)
#define ms(a,b) memset(a,b,sizeof a)
#define F(i,a,b) for (int i=(a);i<=(b);++i)
#define DF(i,a,b) for (int i=(a);i>=(b);--i)
//#define mp make_pair
//#define OO(x) fixed<<setprecision(x)
using namespace std;
//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
inline int read(){
	char ch=getchar(); int w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int M=1e6+10;
int n;
vector<int> v[M];
int mi=1e9,ver=0,sz[M];
void dfs(int x,int fa){
	sz[x]=1;
	int tmp=0;
	for (int y:v[x]){
		if (y^fa){
			dfs(y,x);
			sz[x]+=sz[y];
			tmp=max(tmp,sz[y]);
		}
	}
	tmp=max(tmp,n-sz[x]);
	if (mi>tmp){
		mi=tmp;
		ver=x;
	}
}
int ct[M];
bitset<M> b; 
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	n=read();
//	n=1000000;
	F(i,2,n){
		int x=read();
//		int x=i-1;
		v[x].pb(i); 
		v[i].pb(x);
	}
	dfs(1,0);
	int rt=ver;
	dfs(rt,0);
	LL ans=0;
	F(i,1,n){
		if (i^rt){
			ans+=sz[i];
		}
	}
	for (int x:v[rt]){
		ct[sz[x]]++;
	}
	b.flip(0);
	F(i,1,n){
		if (ct[i]){
			int j=1,num=ct[i];
			while (j<=num){
				b|=(b<<(i*j));	
				num-=j;
				j<<=1;
			}
			if (num){
				b|=(b<<(num*i));	
			}
		}
	}
	LL A=0;
	F(i,0,n){
		if (b[i]){
			A=max(A,ans+1ll*(i+1)*(n-i));
		}
	}
	cout<<A<<"\n";
	return 0;
}
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/