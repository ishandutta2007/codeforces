#include <bits/stdc++.h>
using namespace std;
#define modulo m
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 100000000


int main(){
	
	int t;
	cin>>t;
	
	for(int _=0;_<t;_++){
		int n,m;
		cin>>n>>m;
		
		vector<int> a(n);
		int S = 0;
		for(int i=0;i<n;i++){
			cin>>a[i];
			if(i!=0)S += a[i];
		}
		
		cout<<min(m,a[0]+S)<<endl;
	}
	
	return 0;
}