#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 10000000000000000


int main(){
	
	long long n,m;
	cin>>n>>m;
	
	long long mini = n/m;
	long long maxi = n-(m-1);
	
	long long a = n%m;
	
	long long b = (m-a)*((mini)*(mini-1))/2;
	b += a * (mini+1) * (mini) /2;
	
	cout<<b<<' '<<(maxi*(maxi-1))/2<<endl;
	
	return 0;
}