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
char c[200005];
int s[26][200005];
int temp[26];
int t[26];
int n;
int q;

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n;
	scanf("%s",c);
	for(int i=0;i<n;i++)
	{
		temp[c[i]-'a']++;
		s[c[i]-'a'][temp[c[i]-'a']]=i+1;
	}
//	cout<<s[24][1]<<endl;
	cin>>q;
	while(q--)
	{
		scanf("%s",c);
		memset(t,0,sizeof(t));
		n=strlen(c);
		int res=0;
		for(int i=0;i<n;i++)
		{
			t[c[i]-'a']++;
		}
		for(int i=0;i<26;i++)
		{
			res=max(res,s[i][t[i]]);
		}
		printf("%d\n",res);
	}
	return 0;
}