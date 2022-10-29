#include <bits/stdc++.h>
#define pb push_back
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)(x).size())
using namespace std;
typedef long long ll;

int n,m;
ll x[1<<17],y[1<<17];
int f[17][1<<17],d[1<<17];
vector<int> s;

int main(){
	scanf("%d",&n);
	fore(i,0,n)scanf("%lld%lld",x+i,y+i);
	f[0][n-1]=-1;
	s.pb(n-1);
	for(int i=n-2;i>=0;--i){
		while(SZ(s)>1){
			int j=s[SZ(s)-1],k=s[SZ(s)-2];
			if((x[j]-x[i])*(y[k]-y[i])-(x[k]-x[i])*(y[j]-y[i])<=0)break;
			s.pop_back();
		}
		f[0][i]=s.back();
		d[i]=d[f[0][i]]+1;
		s.pb(i);
	}
	fore(k,1,17)fore(i,0,n){
		if(f[k-1][i]<0)f[k][i]=-1;
		else f[k][i]=f[k-1][f[k-1][i]];
	}
	scanf("%d",&m);
	fore(_,0,m){
		int x,y;
		scanf("%d%d",&x,&y);x--;y--;
		if(d[x]<d[y])swap(x,y);
		for(int k=16;k>=0;--k)if(d[x]-(1<<k)>=d[y])x=f[k][x];
		int r=x;
		if(x!=y){
			for(int k=16;k>=0;--k)if(f[k][x]!=f[k][y])x=f[k][x],y=f[k][y];
			r=f[0][x];
		}
		printf("%d%c",r+1," \n"[_==m-1]);
	}
	return 0;
}