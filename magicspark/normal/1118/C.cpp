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
map<int,int>cnt;
int a[22][22];
int get4(){
	for(auto &v:cnt){
		if(v.second>=4){
			cerr<<v.first<<" "<<v.second<<endl;
			v.second-=4;int ret=v.first;
			if(cnt[v.first]==0)cnt.erase(v.first);
			return ret;
		}
	}
	puts("NO");
	exit(0);
}
int get2(){
	for(auto &v:cnt){
		if(v.second>=2){
			cerr<<v.first<<" "<<v.second<<endl;
			v.second-=2;int ret=v.first;
			if(!cnt[v.first])cnt.erase(v.first);
			return ret;
		}
	}
	puts("NO");
	exit(0);
}
int main(){
	cin>>n;
	for(int i=0;i<n*n;i++){
		int a;
		cin>>a;
		cnt[a]++;
	}
	for(int i=0;i<n/2;i++)for(int j=0;j<n/2;j++)a[i][j]=a[n-i-1][j]=a[i][n-j-1]=a[n-i-1][n-j-1]=get4();
	if(n&1){for(int i=0;i<n/2;i++)a[n/2][i]=a[n/2][n-i-1]=get2(),a[i][n/2]=a[n-i-1][n/2]=get2();a[n/2][n/2]=cnt.begin()->first;}
	puts("YES");
	for(int i=0;i<n;i++)for(int j=0;j<n;j++)cout<<a[i][j]<<(j==n-1?'\n':' ');
	return 0;
}