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
int d[100005];
int n;

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n;
	int x,y;
	for(int i=0;i<n-1;i++)
	{
		scanf("%d%d",&x,&y);
		x--;
		y--;
		d[x]++;
		d[y]++;
	}
	for(int i=0;i<n;i++)
	{
		if(d[i]==2) over("NO");
	}
	cout<<"YES\n";
	return 0;
}