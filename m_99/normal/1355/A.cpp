#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 10000000000000

int main(){
	
	int t;
	cin>>t;
	
	for(int _=0;_<t;_++){
		long long a,K;
		cin>>a>>K;
		
		for(long long i=0;i<K-1;i++){
			string S = to_string(a);
			int mini = 10;
			int maxi = -1;
			for(int j=0;j<S.size();j++){
				int k = S[j]-'0';
				mini = min(k,mini);
				maxi = max(k,maxi);
			}
			a += mini*maxi;
			if(mini==0)break;
		}
		cout<<a<<endl;
	}
	
	return 0;
}