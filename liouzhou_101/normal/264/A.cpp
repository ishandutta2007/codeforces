#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<sstream>
#include<bitset>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<queue>
#include<iomanip>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ld,ld> pdd;
typedef pair<ll,ll> pll;

#define X first
#define Y second

const int MaxN=1000010;

int n;
char s[MaxN];

void DFS(int k)
{
	if (k>n) return;
	if (s[k]=='l') DFS(k+1);
	printf("%d\n",k);
	if (s[k]=='r') DFS(k+1);
}

int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	DFS(1);
	return 0;
}