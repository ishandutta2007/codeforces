#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
//#define endl '\n' 

llo t;
llo n;
llo it[101];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>t;
	while(t--){
		cin>>n;
		llo su=0;
		llo ma=0;
		for(llo i=0;i<n;i++){
			cin>>it[i];
			su+=it[i];
			ma=max(ma,it[i]);
		}
		if(ma>su-ma){
			cout<<"T"<<endl;
			continue;
		}
		if(su%2==1){
			cout<<"T"<<endl;
		}
		else{
			cout<<"HL"<<endl;
		}

	}





	return 0;
}