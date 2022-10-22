#include <bits/stdc++.h>
using namespace std;
#define modulo 998244353
#define mod(mod_x) ((((long long)mod_x)+modulo)%modulo)
#define Inf 1000000000000


int main() {

	long long n,k;
	cin>>n>>k;
	
	long long ans1 = 0;
	for(int i=0;i<k;i++){
		ans1 += n-i;
	}
	
	
	
	long long ans2 = 1;
	
	long long cnt = 0;
	
	vector<int> p(n);
	for(int i=0;i<n;i++)scanf("%d",&p[i]);
	
	bool f = true;
	
	for(int i=0;i<n;i++){
		if(p[i]<=n-k)cnt++;
		else{
			if(!f)ans2 = mod(ans2 * (cnt+1));
			cnt=0;
			f=false;
		}
	}
	
	//ans2 = mod(ans2 * (cnt+1));
	cout<<ans1<<' ';
	cout<<ans2<<endl;
	
    return 0;
}