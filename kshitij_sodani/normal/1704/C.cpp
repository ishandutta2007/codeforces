#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define a first
#define b second
#define pb push_back
#define endl '\n'

llo it[100001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo t;
	cin>>t;
	while(t--){
		llo n,m;
		cin>>n>>m;
		llo ans=m;
		for(llo i=0;i<m;i++){
			cin>>it[i];

		}
		sort(it,it+m);
		if(m==1){
			cout<<2<<endl;
			continue;
		}
		vector<llo> ss;
		for(llo i=0;i<m-1;i++){
			ss.pb(it[i+1]-it[i]-1);
		}
		ss.pb(n-it[m-1]+it[0]-1);
		sort(ss.begin(),ss.end());
		reverse(ss.begin(),ss.end());
		llo ind=0;
		for(auto j:ss){
			llo le=max(j-2*ind,(llo)0);
			ans+=min(2*ind,j);
		//	cout<<j<<":"<<ind<<endl;
			if(le==0){
				continue;
			}
			if(le==1){
				ind++;
				continue;
			}
			if(le==2){
				ind++;
				ans++;
				continue;
			}
			ind+=2;
			ans++;
			
		}
		cout<<ans<<endl;


	}








	return 0;
}