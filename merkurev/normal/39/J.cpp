#include <iostream>
#include <vector>

using namespace std;


const int maxN = 1500500;
char s[maxN];
char p[maxN];
vector<int> res;
int hS[maxN];
int hP[maxN];
int deg[maxN];
int base = 1999;


int getString(int i, int j, int * h)
{
	if(i == 0) return h[j];
	return h[j] - h[i - 1] * deg[j - i + 1];
}


void calcH(char * s, int * h, int n)
{
	h[0] = s[0];
	for(int i = 1; i < n; i++)
	{
		h[i] = h[i - 1] * base + s[i];
	}
}


int main()
{ 
	scanf("%s%s", s, p);
	int n = strlen(s);
	deg[0] = 1;
	for(int i = 1; i < n; i++)
	{
		deg[i] = deg[i - 1] * base;
	}
	int m = strlen(p);
	calcH(s, hS, n);
	calcH(p, hP, m);
	res.reserve(n);
	for(int i = 0; i < n; i++)
	{
		int h1 = getString(0, i - 1, hS);
		int h2 = getString(0, i - 1, hP);
		int h3 = getString(i + 1, n - 1, hS);
		int h4 = getString(i, m - 1, hP);
		if(h1 == h2 && h3 == h4)
		{
			res.push_back(i);
		}
	}
	printf("%d\n", res.size());
	for(int i = 0; i < res.size(); i++)
	{
		printf("%d ", res[i] + 1);
	}
	return 0;
}