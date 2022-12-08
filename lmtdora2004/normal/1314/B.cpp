#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, m;
bool bat[200005];

map<int, bool> sto;
map<int, int> val;
int dp(int l, int r, bool ot, bool od)
{
	int lmao=l*4*n+r*4+ot*2+od;
	if(sto[lmao]) return val[lmao];
	sto[lmao]=true;
	if(l==r-1)
	{
		//cout<<l<<" "<<r<<" "<<ot<<" "<<od<<" "<<(bat[l]|bat[r])<<endl;
		if(ot+od==bat[l]+bat[r]) return val[lmao]=(bat[l]|bat[r]);
		else return val[lmao]=-1000000000;
	}
	int aans=-1000000000;
	int mid=(l+r)/2, aft=mid+1;
	for(int uu=0; uu<=1; uu++)
	{
		for(int ud=0; ud<=1; ud++)
		{
			for(int du=0; du<=1; du++)
			{
				for(int dd=0; dd<=1; dd++)
				{
					if((ot==ud||ot==uu)&&(od==du||od==dd))
					{
						aans=max(aans, dp(l, mid, uu, du)+dp(aft, r, ud, dd)+(uu||ud)+(du||dd)+((uu+ud-ot)|od));
					}
				}
			}
		}
	}
	//cout<<l<<" "<<r<<" "<<ot<<" "<<od<<" "<<aans<<endl;
	return val[lmao]=aans;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	n=(1<<n);
	for(int i=1; i<=m; i++)
	{
		int lmao;
		cin>>lmao;
		bat[lmao]=true;
	}
	int ans=0;
	ans=max(ans, dp(1, n, 0, 0));
	//cout<<ans<<endl;
	ans=max(ans, dp(1, n, 0, 1)+1);
	//cout<<ans<<endl;
	ans=max(ans, dp(1, n, 1, 0)+1);
	//cout<<ans<<endl;
	ans=max(ans, dp(1, n, 1, 1)+1);
	cout<<ans;
}