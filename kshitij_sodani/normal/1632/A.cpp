//#pragma GCC optimize("Ofast,unroll-loops")
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
		string s;
		int ans=0;
		cin>>n;
		cin>>s;
		for(int i=0;i<n;i++){
			if(s[i]=='0'){
				ans--;
			}
			else{
				ans++;
			}
		}
		if(n==1 or (n==2 and ans==0)){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}

	}




 
	return 0;
}