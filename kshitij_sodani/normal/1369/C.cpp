#include <bits/stdc++.h>
using namespace std;
typedef int64_t llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
//#define endl '\n'
llo it[200001];
llo aa[200001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo t;
	cin>>t;
	while(t--){
		llo n,k;
		cin>>n>>k;
		for(llo i=0;i<n;i++){
			cin>>aa[i];
		}
		for(llo i=0;i<k;i++){
			cin>>it[i];
		}
		sort(it,it+k);
		llo l=0;
		//llo r=n-1;
		sort(aa,aa+n);
		llo su=0;	
		llo rr=n-1;
		for(llo j=k-1;j>=0;j--){
			if(it[j]==1){
				su+=2*aa[rr];
				rr-=1;
				continue;
			}
		//	cout<<l<<","<<r<<endl;
			su+=aa[l];
		//	su+=aa[r];
			l+=(it[j]-1);
		}
	//	llo r=n-1;
		for(llo j=0;j<k;j++){
			if(it[j]==1){
				continue;
			}
			su+=aa[rr];
			rr-=1;
		}
		cout<<su<<endl;




	}







	return 0;
}