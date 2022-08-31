
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define a first
#define b second
#define pb push_back
#define endl '\n'

int it[100001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	/*vector<int> ss;
	for(int i=2;i<=1e5;i++){
		if(vis[i]==0){
			ss.pb(i);
			for(int j=i;j<=1e5;j+=i){
				vis[j]=1;
			}
		}
	}*/
	llo t;
	cin>>t;

	while(t--){
		llo n;	
		cin>>n;
		llo st=0;
		llo st2=0;
		llo st3=0;
		set<llo> ss;
		for(int i=0;i<n;i++){
			cin>>it[i];
			ss.insert(it[i]);
			if(it[i]==0){
				st=1;
			}
			if(it[i]==1){
				st2=1;
			}
			if(it[i]==2){
				st3=1;
			}
		}
		if(st+st2==2){
			cout<<"NO"<<endl;
			continue;
		}
		if(st2==0){
			cout<<"YES"<<endl;
			continue;
		}
		string ans="YES";
		for(int i=0;i<n;i++){
			if(ss.find(it[i]-1)!=ss.end()){
				ans="NO";
			}
		}
		cout<<ans<<endl;




	}






	return 0;
}