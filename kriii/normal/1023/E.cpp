#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int n; char S[6],U[505],V[505];

int main()
{
	scanf ("%d",&n);
	int X=1,Y=1;
	for (int i=0;i<n-1;i++){
		printf("? %d %d %d %d\n", X, Y+1, n, n); fflush(stdout);
		scanf("%s", S);
		if (S[0] == 'Y'){
			Y++;
			U[i] = 'R';
		}
		else{
			X++;
			U[i] = 'D';
		}
	}
	int u = X, v = Y;
	for (int i=n-2,x=n,y=n;i>=0;i--){
		if (U[i] == 'R') v--;
		else u--;

		if (y == Y) S[0] = 'Y';
		else if (x == X) S[0] = 'N';
		else{
			printf("? %d %d %d %d\n", u, v, x-1, y); fflush(stdout);
			scanf("%s", S);
		}
		if (S[0] == 'Y'){
			x--;
			V[i] = 'D';
		}
		else{
			y--;
			V[i] = 'R';
		}
	}
	printf ("! %s%s\n",U,V); fflush(stdout);

	return 0;
}