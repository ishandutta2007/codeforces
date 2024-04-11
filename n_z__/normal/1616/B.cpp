#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		string s;
		cin>>s;
		int i=1;
		if(s[0]==s[1]){
			cout<<s[0]<<s[1]<<endl;
			continue;
		} 
		for(i=1;i<n;i++){
			if(s[i]>s[i-1]){
				break;
			}
		}
		i--;
		for(int j=0;j<=i;j++){
			cout<<s[j];
		} 
		for(int j=i;j>=0;j--){
			cout<<s[j];
		}
		cout<<endl;
	} 
}