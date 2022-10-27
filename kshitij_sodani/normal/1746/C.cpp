#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define a first
#define b second
#define pb push_back
#define endl '\n'


llo it[100001];
llo ans[100001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo t;
	cin>>t;
	while(t--){
		llo n;
		cin>>n;
		vector<pair<llo,llo>> ss;
		for(llo i=0;i<n;i++){
			cin>>it[i];
			if(i>0){
				if(it[i-1]>it[i]){
					ss.pb({it[i-1]-it[i],i});
				}
			}
		}
		sort(ss.begin(),ss.end());
		reverse(ss.begin(),ss.end());
		for(llo i=0;i<n;i++){
			if(i<ss.size()){
				ans[n-i]=ss[i].b+1;
			}
			else{
				ans[n-i]=n;
			}
			//cout<<ans[n-i]<<" ";
		}
		for(int i=1;i<=n;i++){
			cout<<ans[i]<<" ";
		}
		
		cout<<endl;


	}





	return 0;
}