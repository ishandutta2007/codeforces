#include <bits/stdc++.h>
using namespace std;
#define modulo 998244353
#define mod(mod_x) ((((long long)mod_x)+modulo)%modulo)
#define Inf 1000000000000



int main() {
	
	int n,m,h;
	cin>>n>>m>>h;
	
	vector<int> a(m),b(n);
	
	for(int i=0;i<m;i++)cin>>a[i];
	for(int i=0;i<n;i++)cin>>b[i];
	
	vector<vector<int>> ans(n,vector<int>(m,0));
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			int x;
			cin>>x;
			if(x==0)continue;
			
			ans[i][j] = min(a[j],b[i]);
		}
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(j!=0)cout<<' ';
			cout<<ans[i][j];
		}
		cout<<endl;
	}
	
    return 0;
}