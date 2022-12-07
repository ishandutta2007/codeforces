#include <bits/stdc++.h>
#define FOR(i, x, y) for(int (i) = (x); (i) <= (y); (i) ++)
using namespace std;
int n, m;
int a[50][50], b[50][50];

bool check() 
{
	FOR(i, 0, n - 1)
	{
    	int tot = 0;
    	FOR(j, 0, m - 1) 
    		if (b[i][j] != j) tot ++;
    	if (tot > 2) return false;
  	}
  	return true;
}
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
int main() 
{
	n = read();
	m = read();
  	FOR(i, 0, n - 1)
	{
    	FOR(j, 0, m - 1) 
    	{
      		a[i][j] = read();
      		a[i][j] --;
    	}
  	}

  	memcpy(b, a, sizeof a);

  	if (check()) 
  	{
    	cout << "YES" << endl;
    	return 0;
  	}

  	FOR(i, 0, m - 1)
  	{
  		FOR(j, i + 1, m - 1)
  		{
      		memcpy(b, a, sizeof a);
      		for (int k = 0; k < n; k ++)
        		swap(b[k][i], b[k][j]);
      		if (check()) 
      		{
        		cout << "YES" << endl;
        		return 0;
      		}
    	}
  	}
  	cout << "NO" << endl;
  	return 0;
  return 0;
}