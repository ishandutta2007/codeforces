#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
int modpow(int x,int y,int md=mod){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
int n,m;
bitset<10005> v[55];
int main(){
	scanf("%d%d",&m,&n);
	for(int i=1;i<=m;i++){
		int x;scanf("%d",&x);
		while(x--){
			int y;scanf("%d",&y);v[i].set(y);
		}
	}
	for(int i=1;i<=m;i++)
		for(int j=i+1;j<=m;j++){
			bitset<10005>_=v[i]&v[j];
			if(_.count())continue;
			puts("impossible");
			return 0;
		}
	puts("possible");
	return 0;
}