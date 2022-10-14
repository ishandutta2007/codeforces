#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=100010;
int t,n,a[N][2],cnt[33][33];
string s;
signed main(){
	ios::sync_with_stdio(0);
	for(cin>>t;t--;){
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>s,a[i][0]=s[0]-96,a[i][1]=s[1]-96;
		int ans=0;
		for(int i=1;i<=n;i++){
			ans+=cnt[a[i][0]][a[i][1]];
			for(int j=1;j<=26;j++){
				if(j!=a[i][0])cnt[j][a[i][1]]++;
				if(j!=a[i][1])cnt[a[i][0]][j]++;
			}
		}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=26;j++){
				if(j!=a[i][0])cnt[j][a[i][1]]--;
				if(j!=a[i][1])cnt[a[i][0]][j]--;
			}
		cout<<ans<<"\n"; 
	}
	return 0;
}