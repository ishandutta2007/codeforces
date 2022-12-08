#include <stdio.h>

bool good[30001];
int N,T;

int main()
{
	scanf ("%d %d",&N,&T);

	good[1] = 1;
	for (int i=1;i<N;i++){
		int x; scanf ("%d",&x);
		if (good[i]) good[i+x] = 1;
	}
	puts(good[T]?"YES":"NO");

	return 0;
}