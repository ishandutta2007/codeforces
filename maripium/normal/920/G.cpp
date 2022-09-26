#include<bits/stdc++.h>
#define int long long
#define double long double
#define pb push_back
#define sp ' '
#define endl '\n'
#define fi first
#define se second
using namespace std;
const int inf=1e8+7,N=1e6+5;
const double pi=acos(-1);
bool nonpr[N]={0};
vector<int> pr[N];
void eratos()
{
	for(int i=2;i<N;++i)
	{
	if(nonpr[i])continue;
	pr[i].pb(i);
	for(int j=i<<1;j<N;j+=i)nonpr[j]=1,pr[j].pb(i);
	}
}
int cntcp(int y,int p)
{
int ans=0,sz=pr[p].size();
for(int mask=0; mask<(1<<sz); ++mask){
	int prd=1,cnt=0;
	for(int i=0;i<sz;++i) if((mask>>i)&1) prd*=pr[p][i], ++cnt;
	if(cnt%2)ans-=(y/prd);
	else ans+=(y/prd);
	//cout<<ans<<endl;
	}
return ans;
}
signed main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	eratos();
	int test,x,p,k;
	cin>>test;
	while(test--){
		cin>>x>>p>>k;
		int m=cntcp(x,p);
		//cout<<m<<endl;
		int l=0,r=inf;
		while(l<r){
		int mid=l+r>>1;
		if(cntcp(mid,p)>=m+k)r=mid;
		else l=mid+1;
		}
		cout<<l<<endl;
		fflush(stdout);
	}
return 0;
}