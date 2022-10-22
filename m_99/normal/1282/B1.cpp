#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000

int main(){
	
	int t;
	cin>>t;
	
	for(int i=0;i<t;i++){
		long long n,p,k;
		cin>>n>>p>>k;
		vector<long long> a(n);
		for(int j=0;j<n;j++)cin>>a[j];
		sort(a.begin(),a.end());
		int ans = 0;
		{
			long long sum = 0;
			int x = -1;
			while(true){
				if(x+k>=n)break;
				if(sum+a[x+k]<=p){
					x+=k;
					sum+=a[x];
					ans = max(ans,x+1);
				}
				else{
					break;
				}
			}
			ans = max(ans,x+1);
		}
		
		long long sum = 0;
		for(int j=0;j<k;j++){
			sum += a[j];
			if(sum>p)break;
			int x = j;
			while(true){
				if(x+k>=n)break;
				if(sum+a[x+k]<=p){
					x+=k;
					sum+=a[x];
				}
				else{
					break;
				}
			}
			ans = max(x+1,ans);

		}
		cout<<ans<<endl;
		
		
	}
	
	
    return 0;
}