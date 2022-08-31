#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;




struct Series
{
	int p, first, last, end;
	Series() : p(), first(), last(), end(-1) {}
	Series(int _p, int _first, int _last, int _end) : p(_p), first(_first), last(_last), end(_end) {}
};




const int maxn = 1e6 + 100;
const int inf = 1e9;
char str[maxn];
int sId[maxn];
Series series[5 * maxn];
int numSeries;
Series open[100];
int numOpen;
Series nopen[100];

char getWait(Series s, int pos)
{
	return str[pos - s.first];
}

void closeSeria(Series s, int pos)
{
	int id = sId[s.first];
	series[id].end = pos;
}

int getZ(int pos, int len)
{
	if (sId[pos] == -1)
		return 0;
	Series s = series[sId[pos] ];
	if (s.end == -1)
		return len - pos;
	return s.end - pos;
}

void addChar(int pos)
{
	if (pos == 0)
	{
		sId[pos] = -1;
		return;
	}
	int nxtOpen = 0;
	for (int i = 0; i < numOpen; i++)
	{
		Series cur = open[i];
		if (getWait(cur, pos) != str[pos] )
		{
			closeSeria(cur, pos);
			continue;
		}
		nopen[nxtOpen++] = cur;
	}
	numOpen = 0;
	int plast = 0, pp = -1;

	sId[pos] = -1;
	if (str[pos] == str[0] )
	{
		nopen[nxtOpen++] = Series(inf, pos, pos, -1);
	}

	for (int i = 0; i < nxtOpen; i++)
	{
		Series cur = nopen[i];
		int fp = cur.first - plast;
		if (fp != cur.p)
		{
			int fId = numSeries;
			if (fp == pp)
			{
				open[numOpen - 1].last += pp;
				fId = sId[open[numOpen - 1].first];
			}
			else
			{
				open[numOpen++] = Series(fp, cur.first, cur.first, -1);
				series[numSeries++] = open[numOpen - 1];
			}
			sId[cur.first] = fId;
			cur.first += cur.p;
		}
		if (cur.first <= cur.last)
		{
			open[numOpen++] = cur;
		}
		plast = open[numOpen - 1].last;
		pp = open[numOpen - 1].p;
	}
}



int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%s", str);
	int len = strlen(str);
	for (int i = 0; i < len; i++)
	{
		addChar(i);
	}
	fprintf(stderr, "%s\n", str);

	int maxBefore = -1;
	for (int i = 1; i < len; i++)
	{
		int z = getZ(i, len);
		if (i + z == len &&  maxBefore >= z)
		{
			str[z] = 0;
			printf("%s\n", str);
			return 0;
		}
		maxBefore = max(z, maxBefore);
	}

	printf("Just a legend");
//	fprintf(stderr, " %d", getZ(i, len) );



	return 0;
}