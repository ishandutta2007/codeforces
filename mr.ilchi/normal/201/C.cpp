#include <iostream>
#include <vector>

using namespace std;

const int maxN=1000*100+5;
long long a[maxN],dp1[maxN],dp2[maxN],dp3[maxN],dp4[maxN];

int main(){
	int n;
	cin >> n;
	for(int i=1 ; i<n ; i++)
		cin >> a[i];

	for(int i=1 ; i<=n ; i++)
		if(a[i-1]%2==0){
			if(a[i-1]!=0){
				dp1[i]=dp1[i-1]+a[i-1];
				dp3[i]=max(dp3[i-1],dp1[i-1])+a[i-1]-1;
			}
		}
		else{
			if(a[i-1]!=1){
				dp1[i]=dp1[i-1]+a[i-1]-1;
				dp3[i]=max(dp3[i-1],dp1[i-1])+a[i-1];
			}
			else{
				dp3[i]=max(dp1[i-1],dp3[i-1])+a[i-1];
			}
		}
//	for(int i=1 ; i<=n ; i++)
//		cout << i << ' ' << dp1[i] << ' ' << dp3[i] << endl;
	for(int i=n-1 ; i>=1 ; i--){
		if(a[i]%2==0){
			if(a[i]!=0){
				dp2[i]=dp2[i+1]+a[i];
				dp4[i]=max(dp2[i+1],dp4[i+1])+a[i]-1;
			}
		}
		else{
			if(a[i]!=1){
				dp2[i]=dp2[i+1]+a[i]-1;
				dp4[i]=max(dp4[i+1],dp2[i+1])+a[i];
			}
			else{
				dp4[i]=max(dp4[i+1],dp2[i+1])+a[i];
			}
		}
	}
	long long Max=0;
	for(int i=1 ; i<=n ; i++){
		Max=max(Max,dp1[i]+max(dp2[i],dp4[i]));
		Max=max(Max,dp2[i]+max(dp1[i],dp3[i]));
	}
//	for(int i=1 ; i<=n ; i++)
//		cout << i << ' ' << dp2[i] << ' ' << dp4[i] << endl;
	cout << Max << endl;

	
	
	return 0;
}