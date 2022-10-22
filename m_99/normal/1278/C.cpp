#include <bits/stdc++.h>
using namespace std;
#define modulo 998244353
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000


int main(){
	
	int t;
	cin>>t;
	
	for(int i=0;i<t;i++){
		int n;
		cin>>n;
		vector<int> a(n),b(n);
		int dif = 0;
		for(int j=0;j<n;j++){
			cin>>a[j];
			if(a[j]==1)dif++;
			else dif--;
		}
		for(int j=0;j<n;j++){
			cin>>b[j];
			if(b[j]==1)dif++;
			else dif--;
		}
		reverse(a.begin(),a.end());
		map<int,int> cnt;
		int now = 0;
		for(int j=0;j<=n;j++){
			if(cnt.count(now))cnt[now] = min(cnt[now],j);
			else cnt[now] = j;
			if(j==n)break;
			if(a[j]==1)now ++;
			else now--;
		}
		//cout<<cnt[0]<<endl;
		int ans = Inf;
		now = 0;
		for(int j=0;j<=n;j++){
			int x = dif-now;
			if(cnt.count(x)){
				ans = min(ans,j+cnt[x]);
			}
			if(j==n)break;
			if(b[j]==1)now ++;
			else now--;
		}
		cout<<ans<<endl;
		
	}
	
	return 0;
}