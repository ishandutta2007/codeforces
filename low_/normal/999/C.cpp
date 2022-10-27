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

deque <int> pos[26];
int n, k;
string S;
vector <int> rem;

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>k>>S;
	
	for (int i=0; i<S.size(); i++) pos[S[i]-'a'].push_back(i);
	while (k--)
	{
		for (int i=0; i<26; i++) if (!pos[i].empty())
		{
			rem.push_back(pos[i].front());
			pos[i].pop_front();
			break;
		}
	}
	
	rem.push_back(inf);
	sort(rem.begin(), rem.end());
	string ans="";
	int ptr=0;
	
	for (int i=0; i<S.size(); i++)
	{
		if (i==rem[ptr]) ptr++;
		else ans.push_back(S[i]);
	}
	
	cout<<ans;
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: