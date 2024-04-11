#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define a first
#define b second
#define pb push_back
#define endl '\n'

llo it[200001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo t;
	cin>>t;
	while(t--){
		llo n;
		cin>>n;
		llo ans=0;
		for(llo i=0;i<n;i++){
			cin>>it[i];
			if(i<n-1){
				ans+=it[i];
			}
		}
		llo su=0;
		for(llo i=0;i<n-1;i++){
			su+=it[i];
			if(su>0 and it[i]==0){
				ans++;
			}
		}
		cout<<ans<<endl;
	}




	return 0;
}