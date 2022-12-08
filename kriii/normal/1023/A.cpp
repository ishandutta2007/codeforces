#include <stdio.h>
#include <functional>
#include <algorithm>
#include <deque>
#include <queue>
using namespace std;

char A[200100],B[200100];

int main()
{
	int n,m;
	scanf ("%d %d",&n,&m);
	scanf ("%s %s",A,B);

	int i,j;
	for (i=0;i<n;i++) if (A[i] != B[i]) break;
	for (j=n-1;j>=0;j--) if (m-(n-j) < 0 || A[j] != B[m-(n-j)]) break;

	if (i == n && n == m) puts("YES");
	else if (i == j && A[i] == '*' && n <= m + 1) puts("YES");
	else puts("NO");
	return 0;
}