#include <iostream>
using namespace std;
int n,m;
int main ()
{
	scanf("%d%d",&n,&m);
	if (n < m) swap(n,m);
	if (n == 1 || m == 1) printf("%d\n",n * m);
	else if ((n == 2 || m == 2) && n * m != 2){ 
		if (n%4 == 0) printf("%d\n",n);
		if (n%4 == 3) printf("%d\n",n + 1);
		if (n%4 == 2) printf("%d\n",n + 2);
		if (n%4 == 1) printf("%d\n",n + 1); 
	}else printf("%d\n",(1 + n * m) / 2); 
	return 0;
}