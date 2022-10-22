#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000000000000


int main(){
	
	long long n,p,d,w;
	cin>>n>>p>>w>>d;
	
	for(long long i=0;i<=1000000;i++){
		long long a = p-d*i;
		if(a<0)continue;
		if(a%w!=0)continue;
		long long cnt = i+(a/w);
		if(cnt>n)continue;
		
		cout<<a/w<<' '<<i<<' '<<n-cnt<<endl;
		return 0;
		
	}
	
	cout<<-1<<endl;
	
	
	
	
    return 0;
}