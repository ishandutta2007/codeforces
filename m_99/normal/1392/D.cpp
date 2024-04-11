#include <bits/stdc++.h>
using namespace std;
#define modulo 998244353
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 100000000000000000

int main(){
	
	int t;
	cin>>t;
	
	for(int _=0;_<t;_++){
		
		int n;
		scanf("%d",&n);

		string s;
		cin>>s;
		
		vector<int> c;
		for(int i=0;i<s.size();i++){
			if(i==0){
				c.push_back(1);
			}
			else{
				if(s[i]==s[i-1])c.back()++;
				else c.push_back(1);
			}
		}
		
		if(c.size()==1){
			printf("%d\n",(n+2)/3);
		}
		else{
			if(c.size()%2==1){
				c[0] += c.back();
				c.pop_back();
			}
			
			int ans = 0;
			for(int i=0;i<c.size();i++){
				ans += c[i]/3;
			}
			printf("%d\n",ans);
		}
		
	}
	
	return 0;
}