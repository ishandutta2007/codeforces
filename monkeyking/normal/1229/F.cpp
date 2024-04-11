#include<bits/stdc++.h>
template <typename T> inline T mabs(T x) {return (x<0?-x:x);}
#define ll long long 
using namespace std;
int n;
int a[35005],l[35005],r[35005];
multiset<ll,greater<ll> > L;
multiset<ll,less<ll> > R;
ll tL,tR,basis,curY;

ll solve(ll t)
{
	L.clear();R.clear();
	for(int i=0;i<=n;i++)
	{
		L.insert(t);
		R.insert(t);
	}
	tL=tR=0;
	basis=0;
	for(int i=0;i<n;i++)
	{
		tL+=-(r[i]-a[i]);
		tR+=-(l[i]-a[i]);
		if(*L.begin()+tL<=0 && *R.begin()+tR>=0)
		{
			L.insert(-tL);
			R.insert(-tR);
		}
		else if(*L.begin()+tL>0)
		{
			basis+=mabs(*L.begin()+tL);
			L.insert(-tL);
			L.insert(-tL);
			R.insert(*L.begin()+tL-tR);
			L.erase(L.begin());
		}
		else
		{
			basis+=mabs(*R.begin()+tR);
			R.insert(-tR);
			R.insert(-tR);
			L.insert(*R.begin()+tR-tL);
			R.erase(R.begin());
		}
		// debug(L,tL);
		// debug(R,tR);
		// debug(basis);
	}
	int ac=0;
	if(t<*L.begin()+tL)
	{
		for(auto x:L)
		{
			if(x+tL<t) break;
			basis+=x+tL-t;
		}
	}
	else
	{
		for(auto x:R)
		{
			if(x+tR>t) break;
			basis+=t-(x+tR);
		}
	}
	return basis;
}

int main()
{
	// freopen("input.txt","r",stdin);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		scanf("%d%d%d",a+i,l+i,r+i);
	}
	// cout<<solve(2)<<endl;
	// return 0;
	ll l=-accumulate(a,a+n,0LL),r=accumulate(a,a+n,0LL),mid,res;
	while(l<=r)
	{
		mid=l+r>>1;
		if(solve(mid)<solve(mid+1))
		{
			res=mid;
			r=mid-1;
		}
		else
		{
			res=mid+1;
			l=mid+1;
		}
	}
	cout<<solve(res)<<endl;
	return 0;
}