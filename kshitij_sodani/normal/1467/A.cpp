
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n' 
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> aa={9,8};
		for(int i=2;i<n;i++){
			aa.pb((aa.back()+1)%10);
		}
		for(int j=0;j<n;j++){
			cout<<aa[j]<<"";
		}
		cout<<endl;
 
 
 
 
	}
 
 
 
 
 
 
 
 
	return 0;
}