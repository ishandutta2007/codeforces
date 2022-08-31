#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define a first
#define b second
#define pb push_back
#define endl '\n'

int it[201];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n,x;
		cin>>n>>x;
		for(int i=0;i<2*n;i++){
			cin>>it[i];
		}
		sort(it,it+2*n);
		string ans="YES";
		for(int i=0;i<n;i++){
			if(it[i+n]>=it[i]+x){

			}
			else{
				ans="NO";
			}
		}
		cout<<ans<<endl;

	}




	return 0;
}