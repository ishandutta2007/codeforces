#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
int modpow(int x,int y,int md){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
int n;
int a[11111];
int main(){
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	int i,cnt=0;
	for(i=0;i<n;){
		int mx=a[i];cerr<<i<<" "<<a[i]<<endl;
		while(i<n&&(i+1)<mx){
			i++;mx=max(mx,a[i]);
			cerr<<i<<" "<<mx<<endl;
		}
		cnt++;i++;
	}
	cout<<cnt<<endl;
	return 0;
}