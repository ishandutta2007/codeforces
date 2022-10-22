#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000




int main(){
	
	int t;
	cin>>t;
	
	for(int i=0;i<t;i++){
		int a,b,c,n;
		cin>>n>>a>>b>>c;
		
		string S;
		cin>>S;
		string ans(n,'-');
		int cnt = 0;
		for(int j=0;j<n;j++){
			if(S[j]=='S'&&a>0){
				a--;
				cnt++;
				ans[j]='R';
			}
			if(S[j]=='R'&&b>0){
				b--;
				cnt++;
				ans[j]='P';
			}
			if(S[j]=='P'&&c>0){
				c--;
				cnt++;
				ans[j]='S';
			}
		}
		if(cnt < (n+1)/2){
			cout<<"NO"<<endl;
			continue;
		}
		for(int j=0;j<n;j++){
			if(ans[j]=='-'){
				if(a>0){
					a--;
					ans[j]='R';
					continue;
				}
				else if(b>0){
					b--;
					ans[j]='P';
					continue;
				}
				else{
					c--;
					ans[j]='S';
					continue;
				}
			}
		}
		cout<<"YES"<<endl;
		cout<<ans<<endl;
	}
		
	
    return 0;
}