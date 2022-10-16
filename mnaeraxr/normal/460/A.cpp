/*
	author:		MarX
	school:		UH
*/

//#include <bits/stdc++.h>
#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <utility>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
typedef vector<int> vi;
#define oo 1000000000
#define MOD 1000007
#define MAX 350

int M[MAX][MAX];
char W[MAX][MAX];

int main()
{
	int n,m,i;
	scanf("%d%d",&n,&m);
	for (i = 1; n > 0; ++i, --n)
		if (i % m == 0)
			n++;
	printf("%d",i - 1);
}