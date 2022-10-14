#include<bits/stdc++.h>
using namespace std;
int const K=15,N=100010,M=4105;
int n,k,q,cnt,a[K][N],p[K];
bitset<M>f[N];
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>k>>q,cnt=k;
	for(int i=0;i<k;i++)
		for(int j=1;j<=n;j++)
			cin>>a[i][j],p[i]=i;
	for(int i=1;i<=k;i++)
		for(int j=0;j<1<<k;j++)
			f[i][j]=j>>(i-1)&1;
	while(q--){
		int op,x,y;
		switch(cin>>op>>x>>y,op){
			case 1:f[++cnt]=f[x]&f[y];break;
			case 2:f[++cnt]=f[x]|f[y];break;
			case 3:{
				sort(p,p+k,[&](const int&lhs,const int&rhs){
					return a[lhs][y]<a[rhs][y];
				});
				for(int i=0,t=0;;i++)
					if(f[x][t|=1<<p[i]]){
						cout<<a[p[i]][y]<<"\n";break;
					}
				break;
			}
		}
	} 
}