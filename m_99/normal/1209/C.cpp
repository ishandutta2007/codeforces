#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 100000000



int main(){
	
	int t;
	cin>>t;
	
	for(int i=0;i<t;i++){
		int n;
		cin>>n;
		
		string s;
		cin>>s;
		bool f = false;
		for(int j=0;j<=9;j++){
			vector<int> ans(n,0);
			int last = j;
			reverse(s.begin(),s.end());
			for(int k=0;k<n;k++){
				if(last>=(s[k]-'0')){
					last=(s[k]-'0');
					ans[n-1-k] = 1;
				}
			}
			reverse(s.begin(),s.end());
			last = j;
			for(int k=0;k<n;k++){
				if(last<=(s[k]-'0')&&ans[k]==0){
					last=(s[k]-'0');
					ans[k]=2;
				}
			}
			bool f2 = true;
			for(int k=0;k<n;k++){
				if(ans[k]==0){
					f2=false;
					break;
				}
			}
			
			if(f2){
				for(int k=0;k<n;k++){
					cout<<ans[k];
				}
				cout<<endl;
				f=true;
				break;
			}			
		}
		
		if(!f){
			cout<<'-'<<endl;
			continue;
		}
		

	}
	
	
	return 0;
}