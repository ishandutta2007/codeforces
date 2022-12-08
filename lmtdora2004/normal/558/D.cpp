#include <bits/stdc++.h>
#define int long long
using namespace std;

int l[55], r[55];
int nowl=0, nowr=0;
vector<pair<int, int> > cac;
int intersect(int x, int y, int z, int t)
{
	if(x>t||y<z) return 0;
	return min(y, t)-max(x, z);
}
signed main()
{
	l[1]=1;
	r[1]=1;
	for(int i=2; i<=50; i++)
	{
		l[i]=l[i-1]*2;
		r[i]=r[i-1]*2+1;
	}
	int n, q;
	cin>>n>>q;
	nowl=l[n];
	nowr=r[n];
	for(int i=1; i<=q; i++)
	{
		int a, b, c, d;
		cin>>a>>b>>c>>d;
		if(d==1)
		{
			while(a<n)
			{
				a++;
				b=b*2;
				c=c*2+1;
			}
			// cout<<nowl<<" "<<nowr<<" "<<c<<" "<<d<<endl;
			if(b>nowr||c<nowl)
			{
				cout<<"Game cheated!";
				return 0;
			}
			else
			{
				nowl=max(nowl, b);
				nowr=min(nowr, c);
			}
		}
		else
		{
			while(a<n)
			{
				a++;
				b=b*2;
				c=c*2+1;
			}
			cac.push_back({b, c});
		}
	}
	// cout<<nowl<<" "<<nowr<<endl;
	sort(cac.begin(), cac.end());
	cac.push_back({1000000000000000000, -1});
	int l=0, r=0;
	vector<int> ans;
	for(int i=0; i<cac.size(); i++)
	{
		if(cac[i].first>r)
		{
			// cout<<l<<" "<<r<<" "<<nowl<<" "<<nowr<<endl;
			if(nowl<=r&&nowr>=l)
			{
				if(l>nowl)
				{
					if(l-nowl==1)
					{
						ans.push_back(nowl);
					}
					else
					{
						cout<<"Data not sufficient!";
						return 0;
					}
				}
				nowl=r+1;
				if(nowl>nowr)
				{
					break;
				}
			}
			l=cac[i].first;
			r=cac[i].second;
		}
		else
		{
			r=max(r, cac[i].second);
		}
	}
	if(nowl==nowr)
	{
		ans.push_back(nowl);
	}
	else if(nowl<nowr)
	{
		cout<<"Data not sufficient!";
		return 0;
	}
	if(ans.size()==1)
	{
		cout<<ans[0];
	}
	else if(ans.size()==0)
	{
		cout<<"Game cheated!";
	}
	else
	{
		cout<<"Data not sufficient!";
	}
}