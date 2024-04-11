#include<bits/stdc++.h>
#define int long long
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
int modpow(int x,int y,int md=mod){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
int n,k,sum;
int a[111111];
int get(int l,int r){
	l--;
	return r*(r+1)/2-l*(l+1)/2;
}
signed main(){
	cin>>n>>k;
	for(int i=0;i<k;i++){
		int l=(i==0?-1:a[i-1]+1),r=(i==0?1e9+5:a[i-1]*2+1);
		int len=k-i-1;
		while(r-l>1){
			int mid=l+r>>1;
			if(sum+get(mid,mid+len)<=n)l=mid;
			else r=mid;
		}
		a[i]=l;sum+=l;
	}
	for(int i=1;i<k;i++)if(a[i]<=a[i-1]||(a[i]>a[i-1]*2))return puts("NO")&0;
	if(sum!=n)return puts("NO")&0;
	puts("YES");
	for(int i=0;i<k;i++)cout<<a[i]<<" ";
	return 0;
}