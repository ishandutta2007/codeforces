#include <bits/stdc++.h>
using namespace std;
#define modulo 998244353
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 100000000

int main(){
	
	int t;
	cin>>t;
	
	for(int _=0;_<t;_++){
		long long n,k;
		cin>>n>>k;
		
		vector ans(n,vector<int>(n,0));
		int y = 0,x = 0;
		for(int i=0;i<k;i++){
			ans[y][x] = 1;
			y++;
			x++;
			if(y>=n)y=0;
			if(x>=n)x=0;
			if(y==0)x++;
		}
		
		int p = 0;
		int Rmin=100000,Rmax=0,Cmin=1000000,Cmax=0;
		for(int i=0;i<n;i++){
			int s = 0;
			for(int j=0;j<n;j++){
				s += ans[i][j];
			}
			Rmin = min(Rmin,s);
			Rmax = max(Rmax,s);
		}
		for(int i=0;i<n;i++){
			int s = 0;
			for(int j=0;j<n;j++){
				s += ans[j][i];
			}
			Cmin = min(Cmin,s);
			Cmax = max(Cmax,s);
		}
		Rmin = abs(Rmin-Rmax);
		Cmin = abs(Cmin-Cmax);
		cout<<Rmin*Rmin + Cmin*Cmin<<endl;
		
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				printf("%d",ans[i][j]);
			}
			printf("\n");
		}
	}
	
	return 0;
}