#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef int64_t llo;
#define mp make_pair
#define pb push_back
#define a first
#define b second
#define endl "\n"
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo n,k;
	cin>>n>>k;
	llo it[n];
	map<llo,llo> aa;
	for(llo i=0;i<n;i++){
		cin>>it[i];	
	}
	sort(it,it+n);
	llo tot=0;
	map<llo,llo> count;
	for(llo i=0;i<n;i++){
		tot+=it[i];		
		if(aa.find(it[i])!=aa.end()){
			aa[it[i]]=max(aa[it[i]],i);
			count[it[i]]+=1;
		}
		else{
			aa[it[i]]=i;
			count[it[i]]=1;
		}
	}
	llo ans=-1;
	llo tot2=0;
	int co=0;
	int co2=n;
	//
	for(auto nn:aa){
		llo cost=0;
		llo kk=max((llo)0,k-count[nn.a]);
		if(kk==0){
			ans=0;
			break;
		}
		tot-=count[nn.a]*nn.a;
		co2-=count[nn.a];
		if(co>=kk){
			cost=(nn.a-1)*(co)-(tot2);
			cost+=kk;
			if(ans==-1){
				ans=cost;
			}
			else{
				ans=min(ans,cost);
			}
		}
		if(co2>=kk){
			cost=-(nn.a+1)*(co2)+(tot);
			assert(cost>=0);
			cost+=kk;
			if(ans==-1){
				ans=cost;
			}
			else{
				ans=min(ans,cost);
			}

		}
		cost=(nn.a-1)*(co)-tot2;
		
		cost+=-(nn.a+1)*(co2)+tot;
		cost+=kk;

		if(ans==-1){
			ans=cost;
		}
		else{
			ans=min(ans,cost);
		}
		co+=count[nn.a];
		tot2+=count[nn.a]*nn.a;

	}
	cout<<ans<<endl;

	return 0;
}