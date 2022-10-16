#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
#define MAX 1e4
#else
#define MAX 1e7
#endif
#define int long long
using namespace std;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
int modpow(int x,int y,int md=mod){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
int n;
vector<int>mp[(int)MAX+5];
inline int lcm(int x,int y){
	return x*y/__gcd(x,y);
}
signed main(){
	scanf("%I64d",&n);
	for(int i=1;i<=n;i++){
		int x;scanf("%I64d",&x);mp[x].push_back(i);
	}
	int ans=inf*inf,ansx=-1,ansy=-1;
	for(int i=1;i<=MAX;i++){
		int cnt=0,x=0,y=0;
		for(int j=i;j<=MAX;j+=i){
			if(mp[j].size()){
				cnt+=mp[j].size();
				if(cnt>=2){
					if(x){
						y=j;
						if(lcm(x,y)<ans){
							ans=lcm(x,y);
							ansx=mp[x][0];
							ansy=mp[y][0];
						}
					}else{
						if(j<ans){
							ans=j;
							ansx=mp[j][0];
							ansy=mp[j][1];
						}
					}
					break;
				}
				if(cnt==1){
					x=j;
				}
			}
		}
	}
	cout<<min(ansx,ansy)<<" "<<max(ansx,ansy)<<endl;
	return 0;
}