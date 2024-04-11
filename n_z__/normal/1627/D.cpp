#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[1000005];
bool f[1000005];
int tmp[1000005];
signed main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		f[a[i]]=1;
	}
	int ans=0;
	for(int i=1000001;i>=1;i--){
		if(!f[i]){
			int k=0;
			for(int j=2;j*i<=1000000;j++){
				if(f[j*i]){
					k++;
					tmp[k]=j;
				}
			}
			bool ok=false;
			for(int j=1;j<k;j++){
				if(__gcd(tmp[j],tmp[j+1])==1){
					ok=true;
					break;
				}
			}
			for(int j=1;j<k-1;j++){
				if(__gcd(tmp[j],tmp[j+2])==1){
					ok=true;
					break;
				}
			}
			if(ok){
				f[i]=1;
				ans++;
			}
		}
	}
	cout<<ans;
}