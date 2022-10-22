#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000000000002


int main(){
	
	int t;
	cin>>t;
	
	for(int _=0;_<t;_++){
		
		int n;
		scanf("%d",&n);
		
		string a,b;
		cin>>a>>b;
		int cnt = 0;
		vector<int> ans;
		for(int i=n-1;i>=1;i--){
			if(a[i]==b[i])continue;
			if(a[0]==b[i]){
				ans.push_back(1);
				if(a[0]=='0')a[0]='1';
				else a[0]='0';
			}
			ans.push_back(i+1);
			reverse(a.begin(),a.begin()+i+1);
			for(int j=0;j<=i;j++){
				if(a[j]=='0')a[j]='1';
				else a[j]='0';
			}
		}
		if(a[0]!=b[0])ans.push_back(1);
		///cout<<a<<endl;
		cout<<ans.size();
		for(int i=0;i<ans.size();i++){
			cout<<' ';
			cout<<ans[i];
		}
		cout<<endl;
		
	}
	
	return 0;
}