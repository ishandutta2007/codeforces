#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000001

int main(){
	
	int t;
	cin>>t;
	
	for(int _=0;_<t;_++){
		int n,m,a,b;
		cin>>n>>m>>a>>b;
		
		vector<string> S(n,string(m,'0'));
		int now = 0;
		for(int i=0;i<n;i++){
			for(int j=0;j<a;j++){
				S[i][now] = '1';
				now = (now+1)%m;
			}
		}
		string ans = "YES";
		for(int i=0;i<m;i++){
			int c = 0;
			for(int j=0;j<n;j++){
				if(S[j][i]=='1')c++;
			}
			if(c!=b){
				ans="NO";
				break;
			}
		}
		cout<<ans<<endl;
		
		if(ans=="YES"){
			for(int i=0;i<n;i++)cout<<S[i]<<endl;
		}
		
	}
	
	return 0;	
}