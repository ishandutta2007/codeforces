#include<set>
#include<map>
#include<deque>
#include<queue>
#include<stack>
#include<cmath>
#include<ctime>
#include<bitset>
#include<string>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<complex>
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;

const int maxn = 210000;

char st[]={"aeiou13579"};

int n;
char str[maxn];

int main()
{
	scanf("%s",str); n=strlen(str);
	int re=0;
	for(int i=0;i<n;i++)
	{
		char cc=str[i];
		int num=0;
		for(int j=0;j<10;j++)
		{
			if(st[j]==cc) num++;
		}
		if(num) re++;
	}
	printf("%d\n",re);
	
    return 0;
}