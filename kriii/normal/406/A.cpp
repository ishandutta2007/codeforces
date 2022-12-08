#include <stdio.h>

int N,arr[1010],v;

int main()
{
	scanf ("%d",&N);
	for (int i=0;i<N;i++) for (int j=0;j<N;j++){
		int x;
		scanf ("%d",&x);
		if (i == j){
			arr[i] = x;
			v ^= arr[i];
		}
	}

	int Q; scanf ("%d",&Q); while (Q--){
		int o;

		scanf ("%d",&o);
		if (o == 1 || o == 2){
			scanf ("%*d");
			v ^= 1;
		}
		else printf ("%d",v);
	}

	return 0;
}