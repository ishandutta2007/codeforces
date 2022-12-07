#include <bits/stdc++.h>
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
} 
int main()
 {
 	int a,b;
 	a = read();
       b = read();
 	int n;
 	n = read();
 	double ANS=100000000.0;
 	int x,y,v;
 	for (int i=1;i<=n;i++)
 	  {
 	      	x = read(); y = read(); v = read();
 	      	double T=sqrt((x-a)*(x-a)+(y-b)*(y-b)) / v;
			ANS=min(T,ANS); 
	  }
	printf("%lf",ANS);
	return 0;
  }