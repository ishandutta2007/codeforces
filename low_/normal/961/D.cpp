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

int GCDif(int a, int b)
{
	if (a<0) return -GCDif(abs(a), abs(b));
	if (b<0) return GCDif(abs(a), abs(b));
	if (b==0) return a;
	if (a%b==0) return b;
	return GCDif(b, a%b);
}

pair <int, int> pnt[mn];
int n;
int line[mn];
map <pair <int, int>, vector <int> > MV;

pair <int, int> VTCP(pair <int, int> A, pair <int, int> B)
{
	pair <int, int> ret={A.first-B.first, A.second-B.second};
//	if (ret.first==0 || ret.second==0) return {abs(ret.first), abs(ret.second)};
	int temp=GCDif(ret.first, ret.second);
//	cerr<<ret.first<<" "<<ret.second<<' '<<temp<<"\n";
	ret={ret.first/temp, ret.second/temp};
	if (ret.first==0) ret.second=1;
	if (ret.second==0) ret.first=1;
	return ret;
}

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	for (int i=1; i<=n; i++) cin>>pnt[i].first>>pnt[i].second, line[i]=0;
	
	if (n<5)
	{
		cout<<"YES";
		return 0;
	}
	
	pair <int, int> t;
	int cur=1;
	while (cur<4)
	{
		MV.clear();
		for (int i=1; i<=n; i++) if (i!=cur)
		{
			t=VTCP(pnt[cur], pnt[i]);
			if (MV.count(t)==0) MV[t]={i};
			else MV[t].push_back(i);
		}
		
		t={-1, 0};
		for (pair<pair <int, int>, vector <int> > p1: MV) 
		{
	//		cerr<<p1.first.first<<" "<<p1.first.second<<"\n";
			if (p1.second.size()>1)
			{
				t=p1.first;
				break;
			}
		}
		
		cerr<<cur<<"\n";
		//cerr<<t.first<<" "<<t.second<<"\n";
		if ( t.first==-1 ) 
		{
			cur++;
			continue;
		}
		
		line[cur]=1;
		for (int i=0; i<MV[t].size(); i++) line[MV[t][i]]=1;
		set <pair <int, int> > ss;
		ss.clear();
		for (int i=1; i<=n; i++) if (line[i]==0)
		{
			for (int j=i+1; j<=n; j++) if (line[j]==0)
			{
				t=VTCP(pnt[i], pnt[j]);
				ss.insert(t);
				if (ss.size()>1)
				{
					cout<<"NO";
					return 0;
				}
			}
			break;
		}
		
		cout<<"YES";
		return 0;
	}
	
	cout<<"NO";
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: