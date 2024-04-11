#include<iostream>
#include<fstream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<deque>
#include<set>
#include<map>
#include<bitset>
#include<ctime>
#include<queue>
using namespace std;
#define int long long
#define mn 10005
#define inf 4444444444444444444
#define mod 1000000009
#define FLN "test"
#define pii pair <int, int>
#define XX first
#define YY second

string arr[mn];

string ask[3], ans[3];
string inp;

int topos[mn];

signed main()
{
	for (int i=0; i<mn; i++)
	{
		int t=i;
		for (int j=0; j<3; j++)
		{
			arr[i].push_back('a'+t%26);
			t/=26;
		}
	}
	
	cin>>inp;
	int n=inp.size();
	
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<3; j++) ask[j].push_back(arr[i][j]);
	}
	
	cout<<"? "<<ask[0]<<endl;
	cin>>ans[0];
	cout<<"? "<<ask[1]<<endl;
	cin>>ans[1];
	cout<<"? "<<ask[2]<<endl;
	cin>>ans[2];
	
	for (int i=0; i<n; i++)
	{
		topos[i]=(ans[0][i]-'a')+(ans[1][i]-'a')*26+(ans[2][i]-'a')*676;
	}
	
	string ANS="";
	ANS.assign(n, 'a');
	for (int i=0; i<n; i++) ANS[topos[i]]=inp[i];
	cout<<"! "<<ANS<<endl;
	exit(0);
}

// PLEASE REMOVE "cout" AND "cerr" DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Code by low_
// Contact me via mail: dung.totuan01@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie_review/