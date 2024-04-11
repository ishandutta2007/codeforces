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
#define pii pair<int,int>
#define pll pair<ll,ll>
#define over(A) {cout<<A<<endl;exit(0);}
#define all(A) A.begin(),A.end()
#define ceil(a,b) ((a-1)/b+1)
#define srand() mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand(l,r) uniform_int_distribution<int>(l,r)(rng)
typedef unsigned long long ull;
const int inf=1039074182;
using namespace std;
int n,m;
string c[105];
bool used[105];
int p[105];

int main()
{
//	freopen("input.txt","r",stdin);
	ios_base::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>c[i];
	}
	int s=0;
	string res;
	for(int i=0;i<n;i++)
	{
		if(used[i]) continue;
		for(int j=i+1;j<n;j++)
		{
			if(used[j]) continue;
			string t=c[j];
			reverse(all(t));
			if(t==c[i])
			{
				used[i]=true;
				used[j]=true;
				s+=2;
				res+=c[i];
				break;
			}
		}
	}
	string f=res;
	reverse(all(f));
	for(int i=0;i<n;i++)
	{
		if(used[i]) continue;
		string t=c[i];
		reverse(all(t));
		if(t==c[i])
		{
			s++;
			res+=c[i];
			break;
		}
	}
	res+=f;
	cout<<res.size()<<endl;
	cout<<res<<endl;
	return 0;
}