#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 10000000000000000


int main(){
	int n;
	cin>>n;
	
	map<long long,long long> b;
	
	for(int i=0;i<n;i++){
		long long a;
		cin>>a;
		b[a]++;
	}
	
	if(b.size()==1){
		cout<<0<<' '<<((long long)n*(n-1))/2<<endl;
	}
	else{
		auto it1 = b.begin();
		auto it2 = b.rbegin();
		
		cout<<(*it2).first-(*it1).first<<' '<<(*it2).second*(*it1).second<<endl;
	}
	
	
	return 0;
}