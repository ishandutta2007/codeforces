//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
llo it[100001];

llo co[100001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo t;
	cin>>t;
	while(t--){
		llo n;
		cin>>n;
		for(llo i=0;i<=n;i++){
			co[i]=0;
		}
		for(llo i=0;i<n;i++){
			cin>>it[i];
			co[it[i]]++;
		}
		llo st=1;
		for(llo i=0;i<=n;i++){
			if(co[i]>(n+1)/2){
				st=0;
			}
		}
		if(st==0){
			cout<<-1<<endl;
			continue;
		}

		llo co=0;
		vector<pair<llo,llo>> ss;
		for(llo i=0;i<n-1;i++){
			if(it[i]==it[i+1]){
				co++;
				if(ss.size()){
					ss.pb({ss.back().b+1,i});
				}
				else{
					ss.pb({0,i});
				}
			}
		}
		if(ss.size()){
			ss.pb({ss.back().b+1,n-1});
		}
		else{
			ss.pb({0,n-1});
		}
		llo ans=co;
		map<llo,llo> kk;
		for(auto j:ss){
			kk[it[j.a]]++;
			kk[it[j.b]]++;
		}
		llo ma=0;
		llo ind=0;
		for(auto j:kk){
			if(j.b>ma){
				ind=j.a;
			}
			ma=max(ma,j.b);
		}
		//cout<<ma<<endl;

		if(ma>(co+1)+1){
			ans+=ma-(co+1+1);
		}
		/*if(ma==(co+1)+1){
			llo st=1;
			for(auto j:ss){
				if(j.a==ind or j.b==ind){
					st=0;
				}
			}
			if(st==1){
				ans++;
			}
		}*/
		cout<<ans<<endl;


	}















 
	return 0;
}