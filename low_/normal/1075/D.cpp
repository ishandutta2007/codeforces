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
#include<sstream>
#include<bitset>
#include<ctime>
using namespace std;
#define int long long
#define inf 444444444444444444
#define mn 100005
#define FLN "test"
#define zis cin

int t, n;
vector <int> dsk[1005];
vector <int> Y, L;
set <int> sY, sL;
int H[1005], par[1005];

void dfsinit_(int u)
{
//	cerr<<u<<'\n';
	for (int i:dsk[u]) if (i!=par[u])
	{
		par[i]=u;
		H[i]=H[u]+1;
		dfsinit_(i);
	}
}

signed main()
{
//	ifstream zis;
//	zis.open(FLN".inp", ios::in);
	
	zis>>t;
	while (t--)
	{
		//INPUT
		zis>>n;
		for (int i=0; i<1005; i++) dsk[i].clear(), H[i]=1, par[i]=-1;
		Y.clear(), L.clear(), sY.clear(), sL.clear();
		int x, y;
		for (int i=1; i<n; i++) 
		{
			zis>>x>>y;
			dsk[x].push_back(y);
			dsk[y].push_back(x);
		}
		int k;
		zis>>k;
		for (int i=0; i<k; i++) 
		{
			zis>>x;
			Y.push_back(x), sY.insert(x);
		}
		
		zis>>k;
		for (int i=0; i<k; i++)
		{
			zis>>x;
			L.push_back(x), sL.insert(x);
		}
		
		dfsinit_(1);
		
		//INTERACT
		int t;
		cout<<"B "<<L[0]<<endl;
		cin>>t;
		if (sY.count(t)==1)
		{
			cout<<"C "<<t<<endl;
			continue;
		}
		
		y=t; //Li's vertex on your tree
		
		//
		x=Y[0];
		for (int i=1; i<Y.size(); i++) if (H[x]>H[Y[i]]) x=Y[i];
		cout<<"A "<<x<<endl;
		cin>>t;
		if (sL.count(t)==1)
		{
			cout<<"C "<<x<<endl;
			continue;
		}
		
		//
		x=-1;
		
		while (y!=-1)
		{
			if (sY.count(y)==1)
			{
				x=y;
				break;
			}
			y=par[y];
		}
		
		if (x==-1)
		{
			cout<<"C -1"<<endl;
			continue;
		}
		
		cout<<"A "<<x<<endl;
		cin>>t;
		if (sL.count(t)==0) cout<<"C -1"<<endl;
		else cout<<"C "<<x<<endl;
	}
	exit(0);
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_