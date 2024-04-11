
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
llo it[30001];
llo pre[30001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo t;
	cin>>t;
	while(t--){
		llo n;
		cin>>n;
		for(llo i=0;i<n;i++){
			cin>>it[i];
		}
		llo ma=1e9;
		llo st=0;

		for(llo i=0;i<n-1;i++){
			llo xx=max(it[i]-it[i+1],(llo)0);
			//cout<<xx<<":"<<ma<<endl;
			if(xx>ma){
				st=1;
				break;
			}
			ma-=xx;
			ma=min(ma,it[i]-xx);

		}


		if(st){
			cout<<"NO"<<endl;
		}
		else{
			cout<<"YES"<<endl;
		}








	}









	return 0;
}