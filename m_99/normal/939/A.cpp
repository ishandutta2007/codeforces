#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 10000000000000000

int main(){
	
	int n;
	cin>>n;
	
	vector<int> l(n);
	for(int i=0;i<n;i++){
		cin>>l[i];
		l[i]--;
	}
	
	for(int i=0;i<n;i++){
		int a = i;
		int b = l[i];
		int c = l[l[i]];
		
		if(a!=b&&b!=c&&c!=a&&l[c]==a){
			cout<<"YES"<<endl;
			return 0;
		}
	}
	
	cout<<"NO"<<endl;
	
	
	return 0;
}