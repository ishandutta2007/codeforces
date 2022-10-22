#include <bits/stdc++.h>
using namespace std;
#define modulo 998244353
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 100000000

int main(){
	
	int n,p;
	cin>>n>>p;
	
	vector<int> a(n);
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	sort(a.begin(),a.end());
	int maxi = 0;
	for(int i=n-1;i>=0;i--){
		maxi = max(maxi,a[i]-i);
	}
	
	int ok = maxi-1;
	int ng = 1000000000;
	while(ng-ok>1){
		int mid = (ok+ng)/2;
		int now = 0;
		int t = mid;
		bool f = true;
		for(int i=0;i<n;i++){
			while(now!=n&&a[now]<=t)now++;
			if(now-i>=p){
				f=false;
				break;
			}
			t++;
		}
		if(f)ok = mid;
		else ng = mid;
	}
	cout<<ok-maxi+1<<endl;
	
	for(int i=maxi;i<=ok;i++){
		if(i!=maxi)printf(" ");
		printf("%d",i);
	}
	cout<<endl;
	
	return 0;
}