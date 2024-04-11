#include <bits/stdc++.h>
#define Mn 1000010
#define pb push_back
using namespace std;
int n;
int A[Mn], B[Mn], C[Mn], D[Mn];

inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}

void c_od(int x)
{
    int len = 0;
    int o = x;
    do
    {
        x = A[x];
        len ++;
    }
    while(x != o);
    vector<int> a, b;
    for(int i = 0; i < len / 2 + 1; i ++)
    {	
        a.pb(x);
        x = A[x];
    }
    for(int i = 0; i < len / 2; i ++)
    {
        b.pb(x);
        x = A[x];
    }
    vector<int> c;
    for(int i = 0; i < len / 2; i ++)
        c.pb(a[i]), c.pb(b[i]);
    c.pb(a.back());
    for(int i = 0; i < (int)c.size(); i ++)
        C[c[i]] = c[(i + 1) % c.size()];
}

void c_ev(int x, int y)
{
    vector<int> a;
    int o = x;
    do
    {
        a.pb(x);
        a.pb(y);
        x = A[x], y = A[y];
    }
    while(x != o);
    for(int i = 0; i < (int)a.size(); i ++)
        C[a[i]] = a[(i + 1) % a.size()];
}

int main()
{
    n = read();
    for(int i = 1; i <= n; i ++) A[i] = read();
    for(int i = 1; i <= n; i ++) 
    	if(B[i] == 0)
    	{
        	int x = i;
        	int len = 0;
        	do
        	{
        	    x = A[x];
            	B[x] = 1;
            	len ++;
        	}
        	while(x != i);
    	    if(len % 2 == 0)
    	    {
   	         	if(D[len]) c_ev(D[len], i), D[len] = 0;
           		else D[len] = i;
        	}
        	else c_od(i);
    }
    for(int i = 1; i <= n; i ++) if(C[i] == 0 || C[C[i]] != A[i]) return printf("-1\n"), 0;
    for(int i = 1; i <= n; i ++) printf("%d%c", C[i], " \n"[i == n]);
    return 0;
}