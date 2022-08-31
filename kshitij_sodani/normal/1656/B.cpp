
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define a first
#define b second
#define pb push_back
#define endl '\n'

int it[200001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	llo t;
	cin>>t;

	while(t--){
		llo n,k;	
		cin>>n>>k;
		set<llo> ss;
		for(int i=0;i<n;i++){
			cin>>it[i];
			ss.insert(it[i]);
		}
		string ans="NO";
		for(int i=0;i<n;i++){
			if(ss.find(it[i]-k)!=ss.end()){
				ans="YES";
			}
		}
		cout<<ans<<endl;




	}






	return 0;
}