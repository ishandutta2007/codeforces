#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000000000000

int main(){

	int n;
	cin>>n;
	
	string S;
	cin>>S;
	
	int L = 0,R = 0;
	
	for(int i=0;i<n;i++){
		if(S[i]=='R')R++;
		else L--;
	}
	
	cout<<R-L+1<<endl;
	
	return 0;
}