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

int a, b;
vector <int> Va, Vb, Vab;

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>a>>b;
	for (int i=1; i*i<=a; i++) if (a%i==0) Va.push_back(i);
	for (int i=1; i*i<=b; i++) if (b%i==0) Vb.push_back(i);
	for (int i=1; i*i<=a+b; i++) if ((a+b)%i==0) Vab.push_back(i);
	
	while (!Vab.empty())
	{
		int D=(a+b)/Vab.back(), R=Vab.back();
		Vab.pop_back();
		
		for (int i=Va.size()-1; i>=0; i--) if (D>=(a/Va[i]) && R>=Va[i])
		{
			cout<<R+D+D+R;
			return 0;
		}
		
		for (int i=Vb.size()-1; i>=0; i--) if (D>=(b/Vb[i]) && R>=Vb[i])
		{
			cout<<R+D+D+R;
			return 0;
		}
	}
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: