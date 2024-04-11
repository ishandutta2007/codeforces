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
		cin>>n;
		string A,B;
		cin>>A>>B;
		vector<vector<bool>> need(20,vector<bool>(20,false));
		bool f = true;
		for(int i=0;i<A.size();i++){
			char a = A[i],b = B[i];
			if(a>b){
				f=false;
				break;
			}
			need[a-'a'][b-'a']=true;
			
		}
		
		if(!f){
			cout<<-1<<endl;
			continue;
		}
		int ans = 0;
		for(int i=0;i<20;i++){
			int t = -1;
			for(int j=i+1;j<20;j++){
				if(need[i][j]){
					t = j;
					ans++;
					break;
				}
			}
			if(t<0)continue;
			
			for(int j=t+1;j<20;j++){
				if(need[i][j])need[t][j]=true;
			}
		}
		
		cout<<ans<<endl;
	}
	
	return 0;
}