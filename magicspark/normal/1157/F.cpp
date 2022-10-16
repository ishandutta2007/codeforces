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
int a[222222],cnt[222222];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i],cnt[a[i]]++;
	int l=0,r=0,ans=cnt[a[0]],ansl=a[0],ansr=a[0];
	while(1){
		while(l<200005&&cnt[l]<2){
			l++;
			if(cnt[l]<2&&(cnt[l]+cnt[l-1])>=ans){
				ans=cnt[l]+cnt[l-1];ansl=l-1;ansr=l;
			}
		}
		if(l==200005)break;
		r=l;int sum=0;
		while(r<=200005&&cnt[r]>=2)sum+=cnt[r],r++;
		if(l&&cnt[l-1])sum+=cnt[l-1];
		if(cnt[r])sum+=cnt[r];
		if(sum>ans){
			ans=sum;
			if(l&&cnt[l-1])ansl=l-1;
			else ansl=l;
			if(cnt[r])ansr=r;
			else ansr=r-1;
		}
		l=r;
	}
	cout<<ans<<endl;
	while(!cnt[ansl])ansl++;
	while(!cnt[ansr])ansr--;
	for(int i=ansr;i>=ansl;i--)cout<<i<<" ",cnt[i]--;
	for(int i=ansl;i<=ansr;i++)while(cnt[i]--)cout<<i<<" ";
	return 0;
}