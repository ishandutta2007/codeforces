#include <stdio.h>
#include <algorithm>
using namespace std;

int d[5];

int main()
{
	int N; scanf("%d", &N); while (N--){
		int x; scanf("%d", &x);
		for (int u : {x+2, x}){
			for (int j=u;j>=0;j--){
				if (d[u] < d[j] + 1)
					d[u] = d[j] + 1;
			}
		}
	}

	printf("%d\n", max({ d[0],d[1],d[2],d[3],d[4] }));

	return 0;
}