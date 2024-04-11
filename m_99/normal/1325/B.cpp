#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 10000000000000000

int main(){
	
	int t;
	cin>>t;
	
	for(int _=0;_<t;_++){
		int n;
		cin>>n;
		
		set<int> S;
		for(int i=0;i<n;i++){
			int a;
			cin>>a;
			S.insert(a);
		}
		
		cout<<S.size()<<endl;
	}
	
	return 0;
}