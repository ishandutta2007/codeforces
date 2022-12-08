#include <stdio.h>

int main()
{
	int n,a,b,c=0;
	scanf ("%d %d %d",&n,&a,&b);
	if (n > a * b){
		puts("-1");
		return 0;
	}
	for (int i=0;i<a;i++){
		int v[101];
		for (int j=0;j<b;j++){
			if (c < n) v[j] = ++c;
			else v[j] = 0;
		}
		if ((b & 1) || i % 2 == 0) for (int j=0;j<b;j++) printf ("%d ",v[j]);
		else for (int j=b-1;j>=0;j--) printf ("%d ",v[j]);
		puts("");
	}
	return 0;
}