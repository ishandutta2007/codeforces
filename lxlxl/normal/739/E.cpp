#include<set>
#include<map>
#include<deque>
#include<queue>
#include<stack>
#include<cmath>
#include<ctime>
#include<bitset>
#include<string>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<complex>
#include<iostream>
#include<algorithm>
#define ll long long
#define ld long double
using namespace std;

const int maxn = 2100;
const ld eps = 1e-18;

int n,A,B;
ld xi[maxn],yi[maxn],zi[maxn];
struct node
{
	ld val;
	int A,B;
}f[maxn];
void upd(node &x,const node &y){ if(x.val<y.val) x=y; }

void dp(const ld mida,const ld midb)
{
	f[0]=(node){0.0,0,0};
	for(int i=1;i<=n;i++) f[i]=(node){-1.0,0,0};
	for(int i=0;i<n;i++)
	{
		node temp,now=f[i];
		
		temp=now;
		upd(f[i+1],temp);
		
		temp=(node){now.val+xi[i+1]+mida,now.A+1,now.B};
		upd(f[i+1],temp);
		
		temp=(node){now.val+yi[i+1]+midb,now.A,now.B+1};
		upd(f[i+1],temp);
		
		temp=(node){now.val+zi[i+1]+mida+midb,now.A+1,now.B+1};
		upd(f[i+1],temp);
	}
}

int main()
{
	scanf("%d%d%d",&n,&A,&B);
	for(int i=1;i<=n;i++) scanf("%Lf",&xi[i]);
	for(int i=1;i<=n;i++) scanf("%Lf",&yi[i]);
	for(int i=1;i<=n;i++) zi[i]=1-(1-xi[i])*(1-yi[i]);
	
	ld la=-n,ra=n,lb,rb,mida,midb;
	while(ra-la>eps)
	{
		mida=(la+ra)/2.0;
		lb=-n,rb=n;
		while(rb-lb>eps)
		{
			midb=(lb+rb)/2.0; dp(mida,midb);
			if(f[n].B==B) break;
			if(f[n].B<B) lb=midb;
			else rb=midb;
		}
		if(f[n].A==A&&f[n].B==B) break;
		if(f[n].A<A) la=mida;
		else ra=mida;
	}
	double ans=f[n].val-mida*A-midb*B;
	printf("%.9lf\n",ans);
	
	return 0;
}