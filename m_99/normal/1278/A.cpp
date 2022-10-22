#include <bits/stdc++.h>
using namespace std;
#define modulo 998244353
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000001


int main(){
	
	int t;
	cin>>t;
	
	for(int i=0;i<t;i++){
		string p;
		cin>>p;
		string h;
		cin>>h;
		
		sort(p.begin(),p.end());
		
		if(p.size()>h.size()){
			cout<<"NO"<<endl;
			continue;
		}
		
		bool f = false;
		for(int j=0;j<h.size()-p.size()+1;j++){
			string s = h.substr(j,p.size());
			sort(s.begin(),s.end());
			if(s==p)f=true;
		}
		if(f)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
		
	}
	
	return 0;
}