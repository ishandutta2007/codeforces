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
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define over(A) {cout<<A<<endl;exit(0);}
#define all(A) A.begin(),A.end()
#define ceil(a,b) ((a-1)/b+1)
#define quickcin ios_base::sync_with_stdio(false);
template <typename T1,typename T2> inline void chmin(T1 &x,T2 b) {if(b<x) x=b;}
template <typename T1,typename T2> inline void chmax(T1 &x,T2 b) {if(b>x) x=b;}
template <typename T1,typename T2> inline void chmod(T1 &x,T2 b) {x%=b,x+=b;if(x>=b) x-=b;}
const int inf=1039074182;
const ll llinf=1LL*inf*inf;
using namespace std;

void solve()
{
	string x;
	cin>>x;
	int len=x.size();
	vector <string> v;
	for(int i=0;i<len;i++)
	{
		if(x[i]=='0') continue;
		string t;
		t.push_back(x[i]);
		for(int j=i+1;j<len;j++)
		{
			t.push_back('0');
		}
		v.push_back(t);
	}
	cout<<v.size()<<endl;
	for(auto x:v)
	{
		cout<<x<<' ';
	}
	cout<<endl;
}

int main()
{
//	freopen("input.txt","r",stdin);
	quickcin;
	int T;
	cin>>T;
	while(T--)
	{
		solve();
	}
	return 0;
}