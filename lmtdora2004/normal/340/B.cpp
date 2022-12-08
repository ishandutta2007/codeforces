#include <bits/stdc++.h>

using namespace std;

pair<int, int> a[305];
int ok[305];
int now[605];
int n;
double dok[605][605];

int ccw(int x, int y, int z)
{
	int xa=a[y].first-a[x].first, xb=a[z].first-a[x].first;
	int ya=a[y].second-a[x].second, yb=a[z].second-a[x].second;
	if(xa*yb>xb*ya) return -1;
	else if(xa*yb==xb*ya) return 0;
	return 1;
}

double area(vector<int> points)
{
	double ok=0;
	for(int i=0; i<(int)points.size(); i++)
	{
		ok+=a[points[i]].first*a[points[(i+1)%points.size()]].second-a[points[i]].second*a[points[(i+1)%points.size()]].first;
	}
	return abs(ok/2);
}

signed main()
{
	cin>>n;
	for(int i=1; i<=n; i++)
	{
		cin>>a[i].first>>a[i].second;
		ok[i]=i;
	}
	pair<int, int> ye={1001, 1001};
	int take=0;
	for(int i=1; i<=n; i++)
	{
		if(a[i]<ye)
		{
			ye=a[i];
			take=i;
		}
	}
	swap(ok[n], ok[take]);
	sort(ok+1, ok+n, [&](int x, int y)
	{
		// cout<<take<<" "<<x<<" "<<y<<" "<<ccw(take,x,y)<<endl;
		if(ccw(take, x, y)==-1) return true;
		return false;
	});
	// for(int i=1; i<n; i++)
	// {
	// 	cout<<ok[i]<<" ";
	// }
	// return 0;
	// cout<<ccw(1,3,4)<<endl;
	// return 0;
	int head=1;
	now[1]=take;
	for(int i=1; i<=n; i++)
	{
		while(head>1&&ccw(now[head-1], now[head], ok[i])==1)
		{
			head--;
		}
		head++;
		now[head]=ok[i];
		// cout<<ok[i]<<" "<<head<<endl;
		// for(int i=1; i<=head; i++)
		// {
		// 	cout<<now[i]<<" ";
		// }
		// cout<<endl;
	}
	// return 0;
	head--;
	// cout<<head<<endl;
	// for(int i=1; i<=head; i++)
	// {
	// 	cout<<now[i]<<endl;
	// }
	// cout<<endl;
	for(int i=head+1; i<=head+head; i++)
	{
		now[i]=now[i-head];
	}
	// cout<<area({1, 4, 2})<<endl;
	// return 0;
	if(head>3)
	{
		// cout<<"toi ngu nguoi"<<endl;
		for(int i=1; i<=head; i++)
		{
			int it=i+2;
			double cur=area({now[i], now[i+1], now[i+2]});
			while(it+1<i+head&&area({now[i], now[i+1], now[it+1]})>cur)
			{
				cur=area({now[i], now[i+1], now[it+1]});
				it++;
			}
			for(int j=i+1; j<=i+head-2; j++)
			{
				cur=area({now[i], now[j], now[max(it, j+1)]});
				while(it+1<i+head&&area({now[i], now[j], now[it+1]})>cur)
				{
					cur=area({now[i], now[j], now[it+1]});
					it++;
				}
				// cout<<i<<" "<<j<<" "<<it<<endl;
				dok[i][j]=cur;
			}
			// cout<<dok[1][3]<<endl;
		}
		// cout<<dok[1][3]<<" "<<dok[3][6]<<endl;
		double dist=0;
		for(int i=1; i<=head; i++)
		{
			for(int j=i+1; j<=i+head-2; j++)
			{
				dist=max(dist, dok[i][j]+dok[j][i+head]);
			}
		}
		cout<<fixed<<setprecision(6)<<dist;
	}
	else
	{
		double dist=0;
		for(int i=1; i<=n; i++)
		{
			if(ok[i]!=now[1]&&ok[i]!=now[2]&&ok[i]!=now[3])
			{
				dist=max(dist, area({now[3], now[2], now[1], ok[i]}));
				// cout<<dist<<endl;
				dist=max(dist, area({now[3], ok[i], now[2], now[1]}));
				// cout<<dist<<endl;
				dist=max(dist, area({now[3], now[2], ok[i], now[1]}));
				// cout<<dist<<endl;
			}
		}
		cout<<fixed<<setprecision(6)<<dist;
	}
}