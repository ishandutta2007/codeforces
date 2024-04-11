#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x))%modulo)
#define Inf 10000000000000000


int main(){
	
	int n,k;
	cin>>n>>k;
	
	vector<long long> a(n);
	
	for(int i=0;i<n;i++)cin>>a[i];
	
	sort(a.begin(),a.end());
	
	vector<long long> b;
	
	for(int i=n/2;i<n;i++){
		b.push_back(a[i]);
	}
	
	int num = 1;
	long long ans = b[0];
	for(int i=0;i<b.size()-1;i++){
		long long x = b[i+1]-b[i];
		if(num*x<=k){
			k-=num*x;
			ans = ans + x;
		}
		else{
			ans += k/num;
			k = 0;
			break;
		}
		num++;
	}
	
	ans += k/num;
	
	cout<<ans<<endl;
	
			
			
	
	
	return 0;
}