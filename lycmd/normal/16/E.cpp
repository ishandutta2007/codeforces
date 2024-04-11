#include<bits/stdc++.h>
#define gb(i,j) ((i)>>((j)-1)&1)
#define cb(i,j,k) (((i)&~(1<<((j)-1)))|(k<<((j)-1)))
using namespace std;
int const N=23,M=300010;
int n;
double p[N][N],f[M];
int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>p[i][j];
	f[0]=1.0;
	for(int i=0;i<1<<n;i++){
		int t=n-__builtin_popcount(i);
		t=t*(t-1)/2;
		if(!t)continue;
		for(int x=1;x<=n;x++)
			if(!gb(i,x))
				for(int y=x+1;y<=n;y++)
					if(!gb(i,y))
						f[cb(i,x,1)]+=f[i]*p[y][x]/t,
						f[cb(i,y,1)]+=f[i]*p[x][y]/t;
	}
	for(int i=1;i<=n;i++)
		cout<<fixed<<setprecision(8)<<f[cb((1<<n)-1,i,0)]<<" ";
	cout<<"\n";
}