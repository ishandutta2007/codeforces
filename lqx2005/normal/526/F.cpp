#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll N=300000;
const ll INF=1e8;
ll n,a[N+5],x;
ll mi[N+5],mx[N+5];
ll ans=0;
map<ll,ll> s; 
void Fill(ll l,ll r,bool flag)// 0/ 
{
	for(ll i=l;i<=r;i++) mi[i]=INF,mx[i]=-INF;
	if(flag) 
	{
		mi[l]=mx[l]=a[l];
		for(ll i=l+1;i<=r;i++) mi[i]=min(a[i],mi[i-1]),mx[i]=max(a[i],mx[i-1]);
		return;
	}
	else
	{
		mi[r]=mx[r]=a[r];
		for(ll i=r-1;i>=l;i--) mi[i]=min(a[i],mi[i+1]),mx[i]=max(a[i],mx[i+1]);
		return;		
	}
	return;
}
bool check(ll l,ll r,ll ma,ll mn)
{
	ll om=max(mx[l],mx[r]),on=min(mi[l],mi[r]);
	if(om!=ma||on!=mn) return false;
	return true;
}
void dfs(ll l,ll r)
{
	if(l==r)
	{
		ans++;
		return;
	}
	ll mid=(l+r)/2;
	Fill(l,mid,0);
	Fill(mid+1,r,1);
	//
	//cout<<l<<" "<<r<<endl;
	for(ll i=mid;i>=l;i--) 
	{
		ll j=mx[i]-mi[i]+i;
		if(j<=mid||i>=j||j<l||j>r) continue;
		if(check(i,j,mx[i],mi[i])) ans++;
	} 
	for(ll i=mid+1;i<=r;i++) 
	{
		ll j=mi[i]-mx[i]+i;
		if(j>mid||j>=i||j<l||j>r) continue;
		if(check(j,i,mx[i],mi[i])) ans++;
	} //cout<<l<<" "<<r<<" "<<ans-de<<endl;
	// 
	s.clear();
	s[mx[mid+1]-mid-1]++;
	
	for(ll ll=mid,r1=mid+1,r2=mid+1;ll>=l;ll--)
	{
		while(r1<=r&&mx[r1]<mx[ll]) 
		{
			s[mx[r1]-r1]--;
			r1++;
		}
		while(r2<r&&mi[r2+1]>=mi[ll])
		{
			r2++;
			s[mx[r2]-r2]++;
		} 
		if(r1>r2) continue;
		ans+=s[mi[ll]-ll];
		
	}
	s.clear();
	s[mx[mid]+mid]++;
	for(ll l1=mid,l2=mid,rr=mid+1;rr<=r;rr++)
	{
		while(l1>=l&&mx[l1]<mx[rr]) 
		{
			s[mx[l1]+l1]--;
			l1--;
		}
		while(l2>l&&mi[l2-1]>=mi[rr])
		{
			l2--;
			s[mx[l2]+l2]++;
		} 
		if(l1<l2) continue;
		ans+=s[mi[rr]+rr];
		
	}
	dfs(l,mid);
	dfs(mid+1,r);
	return;
}

int main()
{
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++)
	{
		scanf("%lld",&x);
		scanf("%lld",&a[x]);
	}
	ans=0;
	dfs(1,n);
	printf("%lld\n",ans);
	return 0;
}