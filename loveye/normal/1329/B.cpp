#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cstdlib>
using namespace std;

int read();
typedef long long ll;
#define fr(i,l,r) for(int i = (l);i <= (r);++i)
#define rf(i,l,r) for(int i = (l);i >= (r);--i)
#define fo(i,l,r) for(int i = (l);i < (r);++i)
#define foredge(i,u,v) for(int i = fir[u],v;v = to[i],i;i = nxt[i])
#define filein(File) freopen(File".in","r",stdin)
#define fileout(File) freopen(File".out","w",stdout)

const int N=35;
int t,d,m,k;
int dp[N];
int calc(int i,int d) {
	if(i<k) return 1<<i;
	return d-(1<<i)+1;
}
int main() {
	cin>>t;
	while(t--) {
		cin>>d>>m;
		int ans=0;
		rf(i,30,0) if(d>>i&1) {k=i; break;}
		fr(i,0,k) {
			int res=calc(i,d);
			dp[i]=1;
			fo(j,0,i) (dp[i]+=dp[j])%=m;
			dp[i]=1ll*dp[i]*res%m;
			(ans+=dp[i])%=m;
		}
		cout<<ans<<endl;
	}
	return 0;
}