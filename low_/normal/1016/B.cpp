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

string s1, s2;
vector <int> v1, v2;
int QAns[1005][1005];

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	for (int i=0; i<1005; i++) for (int j=0; j<1005; j++) QAns[i][j]=0;
	int n, m, q;
	cin>>n>>m>>q>>s1>>s2;
	for (int i=0; i<(int)s1.size()-(int)s2.size()+1; i++) if (s1.substr(i, s2.size())==s2) v1.push_back(i+1), v2.push_back(i+s2.size());
	
	int p1, p2;
	for (int i=1; i<=n; i++) 
	{
		p1=-1, p2=-1;
		for (int j=0; j<v1.size(); j++) if (v1[j]>=i) 
		{
			p1=p2=j;
			break;
		}
		if (p1==-1) continue;
		for (int j=i; j<=n; j++) 
		{
			if (p2<v2.size()) if (j>=v2[p2]) p2++;
			QAns[i][j]=p2-p1;
		}
	}
	while (q--)
	{
		int l, r;
		cin>>l>>r;
		cout<<QAns[l][r]<<'\n';
	}
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: