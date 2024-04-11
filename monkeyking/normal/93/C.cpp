//Original Code:
//#include <iostream>
//#include <algorithm>
//#include <cmath>
//#include <stdio.h>
//#include <stdlib.h>
//#include <vector>
//#include <map>
//#include <queue>
//#include <set>
//#include <string>
//#include <string.h>
//#include <stack>
//#define Endl endl
//#define mp make_pair
//#define ll long long 
//#define pii pair<int,int>
//#define pll pair<ll,ll>
//#define over(A) {cout<<A<<endl;exit(0);}
//#define all(A) A.begin(),A.end()
//#define ceil(a,b) ((a-1)/b+1)
//#define srand() mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//#define rand(l,r) uniform_int_distribution<int>(l,r)(rng)
//typedef unsigned long long ull;
//const int inf=1039074182;
//using namespace std;
//int best=inf;
//int res[6];
//int n;
//int vec[6];
//int len;
//int pa,pb,mut;
//
//void dfs(int x)
//{
//	if(x==5) return;
//	if(x>=best) return;
//	for(int i=0;i<len;i++)
//	{
//		for(int j=0;j<=3;j++)
//		{
//			if((vec[i]<<j)>n) continue;
//			if((vec[i]<<j)==n)
//			{
//				best=x+1;
//				for(int i=0;i<len;i++)
//				{
//					res[i]=vec[i];
//				}
//				res[len]=vec[i]<<j;
//				return;
//			}
//			if(j!=0)
//			{
//				vec[len++]=(vec[i]<<j);
//				dfs(x+1);
//				len--;
//			}
//			for(int k=0;k<len;k++)
//			{
//				if((vec[i]<<j)+vec[k]>n) continue;
//				if((vec[i]<<j)+vec[k]==n)
//				{
//					best=x+1;
//					for(int i=0;i<len;i++)
//					{
//						res[i]=vec[i];
//					}
//					res[len]=(vec[i]<<j)+vec[k];
//					return;
//				}
//				vec[len++]=(vec[i]<<j)+vec[k];
//				dfs(x+1);
//				len--;
//			}
//		}
//	}
//}
//
//void get(int pos)
//{
//	for(pa=0;pa<pos;pa++)
//	{
//		for(pb=0;pb<pos;pb++)
//		{
//			for(mut=0;mut<=3;mut++)
//			{
//				if(res[pos]==res[pa]+res[pb]*(1<<mut))
//				{
//					return;
//				}
//				if(res[pos]==res[pa]*(1<<mut))
//				{
//					pb=-1;
//					return;
//				}
//			}
//		}
//	}
//}
//
//int main()
//{
////	freopen("input.txt","r",stdin);
//	cin>>n;
//	if(n==1) over(0);
//	vec[0]=1;
//	len=1;
//	dfs(0);
//	cout<<best<<endl;
//	pa=pb=-1;
//	mut=-1;
//	for(int i=0;i<best;i++)
//	{
//		get(i+1);
//		if(pb==-1)
//		{
//			printf("lea e%cx, [%d*e%cx]\n",i+1+'a',1<<mut,pa+'a');
//		}
//		else
//		{
//			printf("lea e%cx, [e%cx + %d*e%cx]\n",i+1+'a',pa+'a',1<<mut,pb+'a');
//		}
//	}
//	
//	return 0;
//}

//substituted with C++ Inliner
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
int best=inf;
int res[6];
int n;
int vec[6];
int len;
int pa,pb,mut;

void dfs(int x)
{
	if(x==5) return;
	if(x>=best) return;
	for(int i=0;i<len;i++)
	{
		for(int j=0;j<=3;j++)
		{
			if((vec[i]<<j)>n) continue;
			if((vec[i]<<j)==n)
			{
				best=x+1;
				for(int i=0;i<len;i++)
				{
					res[i]=vec[i];
				}
				res[len]=vec[i]<<j;
				return;
			}
			if(j!=0)
			{
				vec[len++]=(vec[i]<<j);
				dfs(x+1);
				len--;
			}
			for(int k=0;k<len;k++)
			{
				if((vec[i]<<j)+vec[k]>n) continue;
				if((vec[i]<<j)+vec[k]==n)
				{
					best=x+1;
					for(int i=0;i<len;i++)
					{
						res[i]=vec[i];
					}
					res[len]=(vec[i]<<j)+vec[k];
					return;
				}
				vec[len++]=(vec[i]<<j)+vec[k];
				dfs(x+1);
				len--;
			}
		}
	}
}

void get(int pos)
{
	for(pa=0;pa<pos;pa++)
	{
		for(pb=0;pb<pos;pb++)
		{
			for(mut=0;mut<=3;mut++)
			{
				if(res[pos]==res[pa]+res[pb]*(1<<mut))
				{
					return;
				}
				if(res[pos]==res[pa]*(1<<mut))
				{
					pb=-1;
					return;
				}
			}
		}
	}
}

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n;
	if(n==1) over(0);
	vec[0]=1;
	len=1;
	dfs(0);
	cout<<best<<endl;
	pa=pb=-1;
	mut=-1;
	for(int i=0;i<best;i++)
	{
		get(i+1);
		if(pb==-1)
		{
			printf("lea e%cx, [%d*e%cx]\n",i+1+'a',1<<mut,pa+'a');
		}
		else
		{
			printf("lea e%cx, [e%cx + %d*e%cx]\n",i+1+'a',pa+'a',1<<mut,pb+'a');
		}
	}
	
	return 0;
}