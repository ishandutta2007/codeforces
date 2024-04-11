#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000001

int main(){
	
	int t;
	cin>>t;
	
	for(int _=0;_<t;_++){
		int n,m;
		cin>>n>>m;
		
		vector<string> s(n);
		for(int i=0;i<n;i++)cin>>s[i];
		string ans = "";
		for(int i=0;i<m;i++){
			bool f = true;
			set<int> S;
			for(int j=1;j<n;j++){
				int t = 0;
				for(int k=0;k<m;k++){
					if(k==i)continue;
					if(s[0][k]!=s[j][k])t++;
				}
				if(t>=2){
					f=false;
					break;
				}
				if(t==1){
					S.insert(s[j][i]);
				}
			}
			if(!f)continue;
			if(S.size()==0){
				ans = s[0];
				break;
			}
			else if(S.size()==1){
				s[0][i] = *S.begin();
				ans = s[0];
				break;
			}
		}
		
		if(ans=="")cout<<-1<<endl;
		else cout<<ans<<endl;
		
	}
	
	return 0;	
}