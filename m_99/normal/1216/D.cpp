#include <bits/stdc++.h>
using namespace std;
#define modulo 998244353
#define mod(mod_x) ((mod_x)%modulo)
#define Inf 1000000001

long long gcd(long long a, long long b){
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main(){
	
	int n;
	cin>>n;
	
	vector<int> a(n);
	
	int g = 0;
	int maxi = -1;
	int mini = 1000000001;
	
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		mini = min(mini,a[i]);
	}
	
	for(int i=0;i<n;i++){
		a[i] -= mini;
		maxi = max(maxi,a[i]);
		g = gcd(g,a[i]);
	}
	
	long long ans = 0;
	
	for(int i=0;i<n;i++){
		ans += (long long)(maxi-a[i])/g;
	}
	
	cout<<ans<<' '<<g<<endl;
	
    return 0;
}