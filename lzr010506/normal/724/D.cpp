#include <bits/stdc++.h>
#define FOR(i, x, y) for(int (i) = (x); (i) <= (y); (i) ++)
using namespace std;
int n, m, tot[30];
char ch[100010]; 
bool Pd(int x) 
{ 
	int L = 0; 
	FOR(i, 1, n)
	{
		if (ch[i] - 'a' <= x) L = i; 
		if (i - L >= m) return 0; 
	}
	return 1; 
}

void Solve(int x) 
{ 
	FOR(i, 1, n) if (ch[i] - 'a' < x) tot[ch[i] - 'a'] ++ ; 
	int Lx = 0, L = 0; 
	FOR(i, 1, n)
	{ 
		if(ch[i] - 'a' <= x)
		{
			if (ch[i] - 'a' < x) L = i; 
			else Lx = i; 
		}
		if (i - L >= m) L = Lx, tot[x] ++;
	}
	FOR(i, 0, x) while (tot[i] --)  printf("%c", 'a' + i);
	printf("%c", 10);
}	

int main() 
{
	cin >> m;
	scanf("%s", ch + 1);
	n = strlen(ch + 1); 
	FOR(i, 0, 25)
		if (Pd(i)) 
		{
			Solve(i);
			break; 
		}
}