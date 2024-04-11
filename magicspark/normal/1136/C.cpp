#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
int modpow(int x,int y,int md){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
vector<int>a[1001],b[1001];
int main(){
	int n,m;
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++){
			int x;cin>>x;
			a[i+j].push_back(x);
		}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			int x;cin>>x;
			b[i+j].push_back(x);
		}
	}
	for(int i=0;i<=1000;i++)sort(a[i].begin(),a[i].end());
	for(int i=0;i<=1000;i++)sort(b[i].begin(),b[i].end());
	for(int i=0;i<=1000;i++){
		if(a[i]!=b[i]){
			return puts("NO")*0;
		}
	}
	puts("YES");
	return 0;
}