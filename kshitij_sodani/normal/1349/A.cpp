#include <bits/stdc++.h>
#include <iostream>
using namespace std;
typedef int64_t llo;
#define mp make_pair
#define a first
#define b second
#define pb push_back
llo n,m;
vector<pair<llo,llo>> fac[200005];
llo vis[200005];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo ind=1;
	memset(vis,0,sizeof(vis));
	while(ind<200003){
		if(vis[ind]==0){
			for(llo i=ind;i<200003;i+=(ind+1)){
				vis[i]=1;
				llo j=i+1;
				llo co=0;
				while((j)%(ind+1)==0){
					fac[i+1].pb({ind+1,co});
					j/=(ind+1);
					co+=1;
				}
			}
		}
		ind+=1;
	}
	llo n;
	cin>>n;
	llo it[n];
	map<pair<llo,llo>,vector<llo>> kk;
	for(llo i=0;i<n;i++){
		cin>>it[i];
		llo co=0;
		for(auto j:fac[it[i]]){
			if(kk.find(j)==kk.end()){
				kk[j]={j.a};
				continue;
			}
			kk[j].pb(j.a);
		}
	}
	llo ans=1;
	for(auto aa:kk){
		if(aa.b.size()<n-1){
			continue;
		}
		ans*=aa.b[0];
	}
	cout<<ans<<endl;














	return 0;
}