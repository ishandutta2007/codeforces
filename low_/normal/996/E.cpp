#include<iostream>
#include<fstream>
#include<vector>
#include<queue>
#include<deque>
#include<algorithm>
#include<cmath>
#include<set>
#include<map>
#include<cstdio>
using namespace std;
#define int long long
#define inf 9223372036854775799
#define mn 100005
#define FLN "test"

int n;
pair <int, int> Pnt[mn];

pair <int, int> Xet[4];
vector <int> Combi[4];
int ans[mn];

int VLen(pair <int, int> P1)
{
	return P1.first*P1.first+P1.second*P1.second;
}

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	for (int i=1; i<=n; i++) cin>>Pnt[i].first>>Pnt[i].second;
	
	if (n==1)
	{
		cout<<1;
		return 0;
	}
	if (n==2)
	{
		Pnt[1]={Pnt[1].first+Pnt[2].first, Pnt[1].second+Pnt[2].second};
		if (VLen(Pnt[1])>VLen({1500000, 0})) cout<<"1 -1";
		else cout<<"1 1";
		return 0;
	}
	
	Xet[1]=Pnt[1], Combi[1].push_back(1);
	Xet[2]=Pnt[2], Combi[2].push_back(2);
	for (int i=3; i<=n; i++)
	{
		Xet[3]=Pnt[i];
		Combi[3]={i};
		
		int Ma=max(VLen(Xet[1]), VLen(Xet[2]));
		Ma=max(Ma, VLen(Xet[3]));
		
		pair <int, int> temp={inf, inf}, T2;
		for (int i1=1; i1<=3; i1++) if (temp.first==inf)
		{
			for (int i2=i1+1; i2<=3; i2++) if (temp.first==inf)
			{
				T2={Xet[i1].first+Xet[i2].first, Xet[i1].second+Xet[i2].second}, temp={i1, i2};
//				cerr<<Ma<<":\n";
//				cerr<<temp.first<<" "<<temp.second<<" "<<VLen(T2)<<"\n";
				if (VLen(T2)<=Ma) continue;
				T2={Xet[i1].first-Xet[i2].first, Xet[i1].second-Xet[i2].second}, temp={i1, -i2};
//				cerr<<temp.first<<" "<<temp.second<<" "<<VLen(T2)<<"\n";
				if (VLen(T2)<=Ma) continue;
				temp={inf, inf};
			}
		}
		
		int dau=(temp.second/abs(temp.second));
	//	cerr<<temp.second<<"\n";
		temp={abs(temp.first), abs(temp.second)};
		Xet[temp.first]=T2;
		
		while (!Combi[temp.second].empty())
		{
			Combi[temp.first].push_back(Combi[temp.second].back()*dau);
			Combi[temp.second].pop_back();
		}
		
		if (Combi[2].empty())
		{
			Xet[2]=Xet[3];
			Combi[2]=Combi[3];
		}
	}
	
	for (int j=0; j<Combi[1].size(); j++) ans[abs(Combi[1][j])]=Combi[1][j]/abs(Combi[1][j]);
	Xet[1]={Xet[1].first+Xet[2].first, Xet[1].second+Xet[2].second};
	if (VLen(Xet[1])>VLen({1500000, 0})) for (int j=0; j<Combi[2].size(); j++) ans[abs(Combi[2][j])]=-Combi[2][j]/abs(Combi[2][j]);
	else for (int j=0; j<Combi[2].size(); j++) ans[abs(Combi[2][j])]=Combi[2][j]/abs(Combi[2][j]);
	
	for (int i=1; i<=n; i++) cout<<ans[i]<<" ";
	
//	cerr<<VLen({1500000, 0})-VLen({-664123, -282735});
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: