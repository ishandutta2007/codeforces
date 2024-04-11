#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
int modpow(int x,int y,int md=mod){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
int n;
int a[222222],b[222222];
multiset<int>S;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n;i++)cin>>b[i],S.insert(b[i]);
	for(int i=0;i<n;i++){
		int tmp=n-a[i];
		if(S.lower_bound(tmp)==S.end()){
			cout<<(a[i]+*S.begin())%n<<" ";
			S.erase(S.begin());
		}else{
			int t=*S.lower_bound(tmp);
			cout<<(a[i]+t)%n<<" ";
			S.erase(S.find(t));
		}
	}
	return 0;
}