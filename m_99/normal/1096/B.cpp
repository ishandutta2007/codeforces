#include <bits/stdc++.h>
using namespace std;
#define modulo 998244353
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000000000000


int main(){
	
	int n;
	cin>>n;
	
	string s;
	cin>>s;
	
	long long a = 2;
	for(int i=1;i<n;i++){
		if(s[i]==s[i-1])a++;
		else break;
	}
	
	long long b = 2;
	for(int i=n-2;i>=0;i--){
		if(s[i]==s[i+1])b++;
		else break;
	}
	
	if(s[0]==s[n-1]){
		cout<<mod(a*b)<<endl;
	}
	else{
		cout<<mod(a+b-1)<<endl;
	}
	
    return 0;
}