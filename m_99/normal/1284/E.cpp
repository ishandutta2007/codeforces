#include <bits/stdc++.h>
using namespace std;
#define modulo 924844033
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000




int main(){
	
	long double PI = acos((long double)-1);
	
	long long n;
	cin>>n;
	
	vector<double> x(n),y(n);
	
	for(int i=0;i<n;i++){
		cin>>x[i]>>y[i];
	}
	
	long long ans = 0;
	
	for(int i=0;i<n;i++){
		vector<long double> r;
		for(int j=0;j<n;j++){
			if(i==j)continue;
			r.push_back(atan2((long double)y[j]-y[i],(long double)x[j]-x[i]));
		}
		long long ho = 0;
		sort(r.begin(),r.end());
		for(int j=0;j<r.size();j++){
			long long X = lower_bound(r.begin(),r.end(),r[j]+PI)-r.begin();
			X -= j;
			X += lower_bound(r.begin(),r.end(),r[j] - PI)-r.begin();
			X--;
			ho += X * (X-1) * (X-2)/6;
		}
		//cout<<ho<<endl;
		ans += (n-1)*(n-2)*(n-3)*(n-4)/24-ho;
		
	}
	
	cout<<ans<<endl;
	
	
	
    return 0;
}