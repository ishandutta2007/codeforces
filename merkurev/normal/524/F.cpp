#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
using namespace std;



const int maxn = (int) 2e6 + 100;


char str[maxn];
int sa[maxn];

int balBefore[maxn];
int prefMin[maxn];
int prefMax[maxn];
int suffMin[maxn];
int suffMax[maxn];

bool goodPos[maxn];

int bl[2 * maxn];                    
int lca[maxn];
int nbl[2 * maxn];

int n;
int pw;           


int getX(char c)
{
	if (c == '(')
		return 0;
	return 1;
}

bool cmp1(const int &a, const int &b)
{
	return getX(str[a] ) < getX(str[b] );
}                                                     
bool cmp2(const int &a, const int &b)
{
	if (bl[a] != bl[b] )
		return bl[a] < bl[b];
	return bl[(a + pw) % n] < bl[(b + pw) % n];
}
bool cmp2s(const int &a, const int &b)
{
	return bl[(a + pw) % n] < bl[(b + pw) % n];
}

void fillSA()
{
	for (int i = 0; i < n; i++)
		sa[i] = i;
}
void fillBL()
{
	int cur = 1;     
	for (int i = 0; i < n; i++)
	{
		nbl[sa[i] ] = cur;
		if (cmp2(sa[i], sa[i + 1] ) )
			cur++;	
	}
	memcpy(bl, nbl, sizeof nbl);
}

int curAl[maxn];
 
void my_sort()
{
	int prv = 0;
	for (int i = 1; i < n; i++)
	{
		if (bl[sa[i] ] != bl[sa[i - 1] ] )
		{
			sort(sa + prv, sa + i, cmp2s);
			prv = i; 
		}
	}                 
	sort(sa + prv, sa + n, cmp2s);
}


void calcSuff()
{                          
	fillSA();
	sort(sa, sa + n, cmp1);
	for (int i = 0; i < n; i++)
		bl[i] = (str[i] == ')' ? 1 : 0);
	pw = 0;
	fillBL();
	for (int it = 0; it < 20; it++)
	{
		pw = (1 << it);
		my_sort();
		fillBL();
	}
}



int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	scanf("%s", str);
	n = strlen(str);
	for (int i = 0; i < n; i++)
	{
		if (str[i] == '(')
			balBefore[i + 1] = balBefore[i] + 1;
		else
			balBefore[i + 1] = balBefore[i] - 1;
		prefMin[i + 1] = min(prefMin[i], balBefore[i + 1] );
		prefMax[i + 1] = max(prefMax[i], balBefore[i + 1] );
	}
	suffMin[n] = suffMax[n] = balBefore[n];
	for (int i = n - 1; i >= 0; i--)
	{
		suffMin[i] = min(suffMin[i + 1], balBefore[i] );
		suffMax[i] = max(suffMax[i + 1], balBefore[i] );
	}
	
	int bal = balBefore[n];
	if (bal >= 0)
	{
		for (int i = 0; i < n; i++)	
		{
			if (suffMin[i + 1] < balBefore[i] )
				continue;
			if (prefMin[i - 1] + balBefore[n] < balBefore[i] )
				continue;
			goodPos[i] = true;
		}
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			if (suffMin[i + 1] + abs(balBefore[n] ) < balBefore[i] )
				continue;
			if (prefMin[i - 1] < balBefore[i] )
				continue;
			goodPos[i] = true;
		}
	}

	calcSuff();
	for (int i = 0; i < n; i++)
	{
		if (goodPos[sa[i] ] )
		{
			if (bal < 0)
				for (int j = 0; j < abs(balBefore[n] ); j++)
					printf("(");
			for (int j = 0; j < n; j++)
				printf("%c", str[ (sa[i] + j) % n] );
			if (bal > 0)
				for (int j = 0; j < abs(balBefore[n] ); j++)
					printf(")");
			return 0;
		}
	}

	return 0;
}