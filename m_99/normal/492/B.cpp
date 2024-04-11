#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 10000000000000000



int main(){
	
	int n;
	long long l;
	cin>>n>>l;
	l*=2;
	vector<long long> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
		a[i]*=2;
	}
	sort(a.begin(),a.end());
	long long ok = Inf;
	long long ng = 0;
	
	while(ok-ng>1){
		long long mid = (ok+ng)/2;
		bool f = true;
		for(int i=0;i<n-1;i++){
			if(a[i+1]-a[i]>2*mid){
				f=false;
				break;
			}
		}
		if(a[0]>mid)f=false;
		if(l-a.back()>mid)f=false;
		if(!f)ng=mid;
		else ok=mid;
	}
	
	cout<<fixed<<setprecision(10)<<(double)ok/2.0<<endl;
	
    return 0;
}