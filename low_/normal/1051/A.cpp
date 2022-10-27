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
#define inf 92233720368547757
#define mn 100005
#define FLN "test"

bool scase(char c1, char c2)
{
	if (c1>='A' && c1<='Z' && c2>='A' && c2<='Z') return 1;
	if (c1>='a' && c1<='z' && c2>='a' && c2<='z') return 1;
	if (c1>='0' && c1<='9' && c2>='0' && c2<='9') return 1;
	return 0;
}

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int t;
	string s;
	int clow, cup, cnum;
	cin>>t;
	while (t--)
	{
		cin>>s;
		clow=cup=cnum=0;
		for (int i=0; i<s.size(); i++)
		{
			if (s[i]>='a' && s[i]<='z') clow++;
			else if (s[i]>='A' && s[i]<='Z') cup++;
			else if (s[i]>='0' && s[i]<='9') cnum++;
		}
		
//		cerr<<clow<<' '<<cup<<' '<<cnum<<'\n';
		if (clow==0 && cup==0) s[0]='r', s[1]='Y';
		else if (clow==0 && cnum==0) s[0]='r', s[1]='8';
		else if (cnum==0 && cup==0) s[0]='R', s[1]='3';
		else if (clow==0)
		{
			if (scase(s[1], s[0]) || scase(s[1], s[2])) s[1]='p';
			else s[0]='p';
		}
		else if (cup==0)
		{
			if (scase(s[1], s[0]) || scase(s[1], s[2])) s[1]='O';
			else s[0]='O';
		}
		else if (cnum==0)
		{
			if (scase(s[1], s[0]) || scase(s[1], s[2])) s[1]='6';
			else s[0]='6';
		}
		
		cout<<s<<'\n';
	}
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: https://codeforces.com/profile/low_