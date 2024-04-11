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
int n;
char c[55][25];
vector <vector<int> > same[(1<<20)];
double dp[(1<<20)];
int idtocol[55];
int coltoid[55];
int newv_len[256];
int newv[256][55];
//vector <int> newv[256];
char tbd[55];
int tbd_len;

inline int lenof(vector <vector<int> > vec)
{
	int res=0;
	for(auto& x:vec)
	{
		res+=x.size();
	}
	return res;
}

template <typename T>
ostream& operator << (ostream& cout,vector<T> vec)
{
	cout<<"{";
	for(int i=0;i<vec.size();i++)
	{
		cout<<vec[i];
		if(i!=(int)vec.size()-1) cout<<",";
	}
	cout<<"}";
	return cout;
}

inline vector <int> make_vector(int x)
{
	vector <int> temp;
	temp.resize(newv_len[x]);
	for(int i=0;i<newv_len[x];i++)
	{
		temp[i]=newv[x][i];
	}
	return temp;
}

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		scanf("%s",c[i]);
	}
	int m=strlen(c[0]);
	vector <int> t;
	for(int i=0;i<n;i++)
	{
		t.push_back(i);
	}
	if(t.size()>1) same[0].push_back(t);
	for(int mask=1;mask<(1<<m);mask++)
	{
		int low=__builtin_ctz(mask);
		tbd_len=0;
		for(auto &v:same[mask^(1<<low)])
		{
			for(auto &x:v)
			{
				if(newv_len[c[x][low]]==0) tbd[tbd_len++]=(c[x][low]);
				newv[c[x][low]][newv_len[c[x][low]]++]=x;
			}
			for(int i=0;i<tbd_len;i++)
			{
				char x=tbd[i];
				if(newv_len[x]==1 || newv_len[x]==0)
				{
					newv_len[x]=0;
					continue;
				}
				same[mask].push_back(make_vector(x));
				newv_len[x]=0;
			}
			tbd_len=0;
		}
	}
//	int mf;
//	while(cin>>mf)
//	{
//		cout<<lenof(same[mf])<<' '<<same[mf].size()<<endl;
//	}
//	for(int i=0;i<(1<<m);i++)
//	{
//		cout<<lenofsame[i]<<endl;
//	}
	dp[(1<<m)-1]=0;
	for(int mask=(1<<m)-2;mask>=0;mask--)
	{
		int s=0;
		for(int i=0;i<m;i++)
		{
			if((1<<i) & mask) continue;
			s++;
			dp[mask]+=dp[mask | (1<<i)];
		}
		dp[mask]/=s;
		dp[mask]+=1.0*lenof(same[mask])/n;
	}
	cout.precision(10);
	cout<<dp[0]<<endl;
	return 0;
}