#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
int modpow(int x,int y,int md=mod){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
int n,cnt;
int a[300005],b[300005];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&a[i],&b[i]);
		if(a[i]>b[i])cnt++;
	}
	printf("%d\n",max(cnt,n-cnt));
	vector<pair<int,int> >ans;
	if(cnt>n-cnt){
		for(int i=1;i<=n;i++)if(a[i]>b[i])ans.push_back(make_pair(a[i],i)); 
	}else{
		for(int i=1;i<=n;i++)if(a[i]<b[i])ans.push_back(make_pair(-a[i],i));
	}
	sort(ans.begin(),ans.end());
	for(auto p:ans)printf("%d ",p.second);
	return 0;
}