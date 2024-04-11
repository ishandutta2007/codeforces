#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000



int main(){
	
	int n;
	cin>>n;
	
	vector<int> l,r;
	
	for(int i=0;i<n;i++){
		int a,b;
		cin>>a>>b;
		l.push_back(a);
		r.push_back(b);
	}
	
	int k;
	cin>>k;
	
	for(int i=0;i<n;i++){
		if(l[i]<=k&&r[i]>=k){
			cout<<n-i<<endl;
			return 0;
		}
	}
	
    return 0;
}