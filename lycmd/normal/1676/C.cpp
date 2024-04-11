#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=55;
int t,n,m;
string s[N];
signed main(){
	ios::sync_with_stdio(0);
	for(cin>>t;t--;){
		cin>>n>>m;
		for(int i=1;i<=n;i++)
			cin>>s[i];
		int mn=INT_MAX;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++){
				int t=0;
				for(int p=0;p<m;p++)
					t+=abs(s[i][p]-s[j][p]);
				mn=min(mn,t);
			}
		cout<<mn<<"\n";
	}
	return 0;
}