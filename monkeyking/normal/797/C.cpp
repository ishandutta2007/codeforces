#include <iostream>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <string.h>
#include <stack>
#include <assert.h>
#include <bitset>
#define Endl endl
#define mp make_pair
#define ll long long 
#define ull unsinged long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define over(A) {cout<<A<<endl;exit(0);}
#define all(A) A.begin(),A.end()
#define ceil(a,b) ((a-1)/b+1)
#define srand() mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand(l,r) uniform_int_distribution<int>(l,r)(rng)
template <typename T1,typename T2> inline void chmin(T1 &x,T2 b) {if(b<x) x=b;}
template <typename T1,typename T2> inline void chmax(T1 &x,T2 b) {if(b>x) x=b;}
const int inf=1039074182;
using namespace std;
int n;
string s;
stack <char> stk;
int k;
set <pair<char,int> > squ;
string t;
int lastChar[256];

inline void searchStack(char c)
{
	while(!stk.empty() && stk.top()<=c)
	{
		t.push_back(stk.top());
		stk.pop();
	}
}

int main()
{
//	freopen("input.txt","r",stdin);
	ios_base::sync_with_stdio(false);
	cin>>s;
	n=s.size();
	memset(lastChar,-1,sizeof(lastChar));
	for(int i=0;i<n;i++)
	{
		lastChar[s[i]]=i;
	}
	for(char c='a';c<='z';c++)
	{
		if(lastChar[c]==-1) continue;
		searchStack(c);
		for(int i=k;i<n;i++)
		{
			if(i>lastChar[c]) break;
			stk.push(s[i]);
			k=i+1;
			searchStack(c);
		}
	}
	cout<<t<<endl;
	assert(t.size()==n);
	return 0;
}