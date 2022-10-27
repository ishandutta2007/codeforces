#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define a first
#define b second
#define pb push_back
#define endl '\n'


int it[101];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;

		string ans="NO";
		
		for(int i=0;i<n;i++){
			cin>>it[i];
			if(it[i]==1){
				ans="YES";
			}
		}
		/*if(n==3 and k==2){
			if(it[0]==0 and it[1]==1 and it[2]==0){
				cout<<"NO"<<endl;
				continue;
			}
		}*/
		cout<<ans<<endl;
	}






	return 0;
}