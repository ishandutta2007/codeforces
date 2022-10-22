#include <bits/stdc++.h>
using namespace std;
#define N 300005
#define LIM 1000005
#define pb push_back
#define gc() (P1==P2 && (P2=(P1=buf)+fread(buf,1,LIM,stdin),P1==P2)?EOF:*P1++)
const int B=1e3;
char *P1,*P2,buf[LIM];
int T,n,m,b[N],ps[N];vector<int> a[N],vc[N];
int rd()
{
	int res=0;char c=0;while(!isdigit(c)) c=gc();
	while(isdigit(c)) res=res*10+c-48,c=gc();return res;
}
bool slv(int x)
{
	for(int i=1;i<=n;++i) ps[i]=a[i].size()-1;
	for(auto i:a[x]) for(auto j:vc[i])
	{
		if(ps[j]<a[j].size()-1 && a[j][ps[j]+1]==i) ++ps[j];
		else while(~ps[j] && a[j][ps[j]]!=i) --ps[j];
		if(ps[j]==-1) return 0;
	}return 1;
}
void slv()
{
	srand(time(0));n=rd();for(int i=1;i<=n;++i) vc[i].clear();
	n=rd();for(int i=1;i<=n;++i) b[i]=i,a[i].clear();
	for(int i=1,x;i<=n;++i)
	{m=rd();for(int j=1;j<=m;++j) x=rd(),a[i].pb(x),vc[x].pb(i);}
	random_shuffle(b+1,b+n+1);
	for(int i=1;i<=min(n,B);++i) if(!slv(i)) {puts("Human");return;}
	puts("Robot");
}
int main() {T=rd();while(T--) slv();return 0;}