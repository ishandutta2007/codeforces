#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
typedef int64_t llo;
#define a first
#define  b second
#define endl "\n"

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo n;
	cin>>n;
	llo it[n];
	llo k=25;
	for(llo i=0;i<n;i++){
		cin>>it[i];
	}
	llo pre[k+3];
	pre[0]=1;
	for(llo i=1;i<k+3;i++){
		pre[i]=pre[i-1]*2;
	}
	llo tt[n][k];
	for(llo i=0;i<n;i++){
		tt[i][k-1]=it[i];
		for(llo j=k-2;j>=0;j--){
			if(tt[i][j+1]&pre[j+1]){
				tt[i][j]=tt[i][j+1]-pre[j+1];
			}
			else{
				tt[i][j]=tt[i][j+1];
			}
		}
	}
/*	for(int i=0;i<n;i++){
		for(int j=0;j<k;j++){
			cout<<tt[i][j]<<" ";
		}
		cout<<endl;
	}*/
	llo ans=0;
	for(llo kk=0;kk<24;kk++){
		vector<llo> vis;//;multiset<llo> vis;
		for(llo i=0;i<n;i++){
			vis.pb(tt[i][kk+1]);
		}
		sort(vis.begin(),vis.end());
		llo co=0;
		llo nn=vis.size();
		for(auto jj=0;jj<n;jj++){
			llo j=vis[jj];
			llo ind=lower_bound(vis.begin(),vis.end(),pre[kk+1]-j)-vis.begin();//-vis.begin();
			llo ind2=lower_bound(vis.begin(),vis.end(),pre[kk+2]-j)-vis.begin();
			llo ind3=lower_bound(vis.begin(),vis.end(),pre[kk+2]+pre[kk+1]-j)-vis.begin();

			if(j>=pre[kk+1]-j and j<pre[kk+2]-j){
				ind+=1;
			}
			if(j>=pre[kk+1]+pre[kk+2]-j){
				ind+=1;
			}


			co+=max(n-ind-(ind3-ind2),(llo)0);
		}
/*		if(co%2==1){
			while(true){
				continue;
			}
		}*/
		co/=2;
		if(co%2==0){
			continue;
		}
	//	cout<<kk+1<<endl;
		ans+=pre[kk+1];

	}
	llo coo=0;
	for(llo i=0;i<n;i++){
		if(it[i]%2==1){
			coo+=1;

		}
	}

	if((coo*(n-coo))%2==1){
		ans+=1;
	}
	cout<<ans<<endl;
















	return 0;
}