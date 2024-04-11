#include <bits/stdc++.h>
using namespace std;
#define modulo m
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 100000000


int main(){
	
	int t;
	cin>>t;
	
	for(int _=0;_<t;_++){
		int n;
		cin>>n;
		
		string s;
		cin>>s;
		
		vector<pair<string,int>> V;
		
		for(int i=0;i<n;i++){
			string t = s.substr(i);
			string k(s.begin(),s.begin()+i);
			if((n-i)%2==1){
				reverse(k.begin(),k.end());
			}
			t += k;
			V.emplace_back(t,i);
			//cout<<t<<endl;
		}
		
		sort(V.begin(),V.end());
		
		cout<<V[0].first<<endl<<V[0].second+1<<endl;
	}
	
	return 0;
}