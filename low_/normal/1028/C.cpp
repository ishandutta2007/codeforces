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
#define inf 1000000003
#define mn 200005
#define FLN "test"

class rectangle{
public:
	pair <int, int> botleft;
	pair <int, int> toprite;
	
	int size()
	{
		return max((int)0, toprite.first-botleft.first+1)*max((int)0, toprite.second-botleft.second+1);
	}
	
	void print()
	{
		cout<<botleft.first<<"-"<<botleft.second<<" "<<toprite.first<<"-"<<toprite.second<<" "<<size()<<"\n";
	}
	
	rectangle()
	{
		toprite={inf, inf};
		botleft={-inf, -inf};
	}
};

rectangle RCT[mn];
int n;

rectangle Ghep(rectangle A, rectangle B)
{
	rectangle ret;
	ret.botleft={max(A.botleft.first, B.botleft.first), max(A.botleft.second, B.botleft.second)};
	ret.toprite={min(A.toprite.first, B.toprite.first), min(A.toprite.second, B.toprite.second)};
	return ret;
}

rectangle dpf[mn], dps[mn];
main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	for (int i=1; i<=n; i++) cin>>RCT[i].botleft.first>>RCT[i].botleft.second>>RCT[i].toprite.first>>RCT[i].toprite.second;
	
	for (int i=2; i<=n; i++) dpf[i]=Ghep(dpf[i-1], RCT[i-1]);
	for (int i=n-1; i>=1; i--) dps[i]=Ghep(dps[i+1], RCT[i+1]);
	
	rectangle temp;
	for (int i=1; i<=n; i++) 
	{
		temp=Ghep(dpf[i], dps[i]);
//		temp.print();
		if (temp.size()>0)
		{
			cout<<temp.botleft.first<<' '<<temp.botleft.second;
			return 0;
		}
	}
	//cout<<-1;
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: