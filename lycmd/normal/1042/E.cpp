#include<bits/stdc++.h>
#define int long long
#define to first
#define w second
using namespace std;
int const N=1010,MOD=998244353;
int n,m,sx,sy,a[N][N],f[N][N];
vector<int>b;
int qpow(int x,int y){
	return y?qpow(x*x%MOD,y>>1)*(y&1?x:1)%MOD:1;
}
namespace solve1{
	int solve(int x,int y){
		if(f[x][y])
			return f[x][y];
		int cnt=0,ans=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				cnt+=a[i][j]<a[x][y];
		cnt=qpow(cnt,MOD-2);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				if(a[i][j]<a[x][y])
					ans=(ans+(solve(i,j)+(i-x)*(i-x)+(j-y)*(j-y))*cnt%MOD)%MOD;
		return f[x][y]=ans;
	}
}
namespace solve2{
	struct node{
		int x,y,val;
		int operator<(const node&rhs)const{
			return val<rhs.val;
		}
	};
	vector<node>v;
	int const M=N*N;
	int f[M],sx[M],sy[M],srx[M],sry[M],sf[M];
	int solve(int ex,int ey){
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				v.push_back({i,j,a[i][j]});
		v.push_back({0,0,-1});
		sort(v.begin(),v.end());
		for(int i=1;i<v.size();i++){
			int x=v[i].x,y=v[i].y,id=v[i].val;
			sx[i]=(sx[i-1]+x)%MOD,srx[i]=(srx[i-1]+x*x%MOD)%MOD;
			sy[i]=(sy[i-1]+y)%MOD,sry[i]=(sry[i-1]+y*y%MOD)%MOD;
			if(id)f[i]=((srx[id]+sry[id]+sf[id]-2*x*sx[id]%MOD-2*y*sy[id]%MOD+2*MOD)*qpow(id,MOD-2)%MOD+x*x+y*y)%MOD;
			sf[i]=(sf[i-1]+f[i])%MOD;
			if(x==ex&&y==ey)
				return f[i];
		}
	}
}
#define node pair<int,int>
signed main(){
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>a[i][j],b.push_back(a[i][j]);
	cin>>sx>>sy;
	sort(b.begin(),b.end());
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			a[i][j]=lower_bound(b.begin(),b.end(),a[i][j])-b.begin();
	if(n<=50&&m<=50){
		cout<<solve1::solve(sx,sy)<<"\n";
	}else{
		cout<<solve2::solve(sx,sy)<<"\n";
	}
}