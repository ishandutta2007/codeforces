#include <bits/stdc++.h>
using namespace std;
#define modulo 998244353
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 100000000000000000

int main(){
	
	int n;
	cin>>n;
	
	vector<vector<long long>> grid(n,vector<long long>(n,0LL));
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(j%2==0)continue;
			grid[i][j] = 1LL<<((long long)i+j);
		}
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(j!=0)cout<<' ';
			cout<<grid[i][j];
		}
		cout<<endl;
	}
	
	int q;
	cin>>q;
	
	for(int i=0;i<q;i++){
		long long y=0,x=0;
		long long t;
		cin>>t;
		
		vector<pair<int,int>> p(1,make_pair(y,x));
		
		while(y!=n-1||x!=n-1){
			if(y==n-1){
				x++;
				p.emplace_back(y,x);
				continue;
			}
			if(x==n-1){
				y++;
				p.emplace_back(y,x);
				continue;
			}
			long long X = max(grid[y+1][x],grid[y][x+1]);
			if(grid[y+1][x]!=0){
				if(t&X){
					y++;
					
				}
				else{
					x++;
				}
			}
			else{
				if(t&X){
					x++;
				}
				else{
					y++;
				}
			}
			p.emplace_back(y,x);
		}
		
		for(int i=0;i<p.size();i++){
			cout<<p[i].first+1<<' '<<p[i].second+1<<endl;
		}
	}
					
			
	
	return 0;
}