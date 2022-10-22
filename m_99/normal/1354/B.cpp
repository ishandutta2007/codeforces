#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000


int main(){
	
	int t;
	cin>>t;
	
	for(int _=0;_<t;_++){
		string s;
		cin>>s;
		int ans = Inf;
		vector<int> c(3,0);
		
		int r = 0;
		for(int i=0;i<s.size();i++){
			while(r!=s.size()&&(c[0]==0||c[1]==0||c[2]==0)){
				c[s[r]-'1']++;
				r++;
			}
			if(c[0]==0||c[1]==0||c[2]==0)break;
			ans = min(ans,r-i);
			c[s[i]-'1']--;
		}
		if(ans==Inf)printf("0\n");
		else printf("%d\n",ans);
	}
	
	return 0;
}