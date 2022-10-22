#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000001

int main(){
	
	int t;
	cin>>t;
	
	for(int _=0;_<t;_++){
		int n;
		cin>>n;
		
		vector<int> s(n);
		for(int i=0;i<n;i++)scanf("%d",&s[i]);
		
		sort(s.begin(),s.end());
		
		bool f = false;
		for(int i=0;i<n-1;i++){
			if(s[i+1]-s[i]==1)f=true;
		}
		if(f){
			cout<<"YES"<<endl;
			continue;
		}
		int c = 0;
		for(int i=0;i<n;i++)c += s[i]%2;
		
		if(c%2==0)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	
	return 0;	
}