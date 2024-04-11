
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n' 


llo aa[10];
llo it[100001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	for(llo i=0;i<6;i++){
		cin>>aa[i];
	}
	llo n;
	cin>>n;
	for(llo i=0;i<n;i++){
		cin>>it[i];
	}
	sort(aa,aa+6);
	sort(it,it+n);
	llo ans=1e9;
	for(llo i=0;i<n;i++){
		for(llo j=0;j<6;j++){
			llo ma=it[i]-aa[j];
			vector<pair<llo,llo>> pp;
			llo mi=ma;
			for(llo k=0;k<6;k++){
				llo low=0;
				llo high=n-1;
				if(it[0]-aa[k]>ma){
					continue;
				}
				while(low<high-1){
					llo mid=(low+high)/2;
					if(it[mid]-aa[k]<=ma){
						low=mid;
					}
					else{
						high=mid;
					}
				}
				llo ind=low;
				if(it[high]-aa[k]<=ma){
					ind=max(ind,high);
				}
				pp.pb({ind,aa[k]});
			}
			if(pp.size()==0){
				continue;
			}
			llo pre=0;
			llo mop=-1;
			sort(pp.begin(),pp.end());
			//reverse(pp.begin(),pp.end());

			for(int j=pp.size()-1;j>=0;j--){
				if(mop==-1){
					mop=pp[j].b;
				}
				mop=min(mop,pp[j].b);
				llo ind=0;
				if(j>0){
					ind=pp[j-1].a+1;
				}
				if(ind==n){
					continue;
				}
				mi=min(mi,it[ind]-mop);
			}
			if(pp.back().a!=n-1){
				continue;
			}
			/*if(ma==mi){
				for(auto j:pp){
					cout<<j.a<<","<<j.b<<endl;
				}
				return 0;
			}*/
			ans=min(ans,ma-mi);
		}
	}
	cout<<ans<<endl;
	



	return 0;
}