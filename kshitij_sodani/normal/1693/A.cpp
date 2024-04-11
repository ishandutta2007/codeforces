#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define a first
#define b second
#define pb push_back
#define endl '\n'
llo t;
llo it[200001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>t;
	while(t--){
		llo n;
		cin>>n;
		for(llo i=0;i<n;i++){
			cin>>it[i];
		}
		string ans="Yes";
		for(int i=0;i<n-1;i++){
			if(it[i]==0){
				break;
			}
			if(it[i]<0){
				ans="No";
				break;
			}
			it[i+1]=it[i+1]+it[i];
			it[i]=0;
		}
		
		for(int i=0;i<n;i++){
			if(it[i]!=0){
				ans="No";
			}
		}
		cout<<ans<<endl;
	}



 
 
 
	return 0;
}