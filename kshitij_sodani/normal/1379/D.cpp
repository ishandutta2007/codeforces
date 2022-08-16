#include <bits/stdc++.h>
using namespace std;
typedef int64_t llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
//#define endl '\n'
llo n,h,m,k;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>h>>m>>k;
	if(k==0){
		cout<<0<<" "<<0<<endl;
		cout<<endl;
		return 0;
	}
	vector<pair<llo,llo>> it;
	for(llo i=0;i<n;i++){
		llo aa,bb;
		cin>>aa>>bb;
		it.pb({(bb)%(m/2),i});
		it.pb({(bb%(m/2))+m/2,i});
	}
	sort(it.begin(),it.end());
	int ind2=0;
	int ans=n+1;
	int ind=0;
	for(int i=n;i<2*n;i++){
		while(it[ind2].a<=it[i].a-k){
			ind2+=1;
		}
	//	cout<<it[i].a<<s;
//	cout<<i<<":"<<ind2<<endl;

		if(i-ind2<ans){
			ans=i-ind2;
			ind=i;
		}
	}
	cout<<ans<<" "<<it[ind].a-m/2<<endl;
	for(int i=ind-ans;i<ind;i++){
		cout<<it[i].b+1<<" ";
	}
	cout<<endl;


	




 
 
	return 0;
}