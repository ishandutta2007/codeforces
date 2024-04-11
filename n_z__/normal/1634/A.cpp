#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		string s;
		cin>>s;
		int i=0,j=s.size()-1;
		bool ok=1;
		while(i<j){
			if(s[i]!=s[j]){
				ok=0;
			}
			i++;
			j--;
		}
		if(k==0){
			cout<<1;
		}
		else if(ok){
			cout<<1;
		}
		else{
			cout<<2;
		}
		cout<<endl;
	}
	return 0;
}