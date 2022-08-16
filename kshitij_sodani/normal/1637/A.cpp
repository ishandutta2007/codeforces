//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'

int it[100001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		string ans="NO";
		for(int i=0;i<n;i++){
			cin>>it[i];
			if(i>0){
				if(it[i-1]>it[i]){
					ans="YES";
				}
			}
		}
		cout<<ans<<endl;
	}



	


 
	return 0;
}