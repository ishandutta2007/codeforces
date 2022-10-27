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

int n, k;
string s;
int indx[mn*2];
vector <int> st;
int pt=1;

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>k>>s;
	for (int i=0; i<s.size(); i++)
	{
		if (s[i]=='(') 
		{
			st.push_back(pt);
			indx[i]=pt;
			pt++;
		}
		else
		{
			indx[i]=st.back();
			st.pop_back();
		}
	}
	
	for (int i=0; i<s.size(); i++) if (indx[i]<=k/2) cout<<s[i];
	
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: