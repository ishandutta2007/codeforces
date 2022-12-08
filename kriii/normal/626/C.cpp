#include <stdio.h>

int n,m;

bool chk(int a)
{
	int p = a / 2, q = a / 3, r = a / 6;
	return n <= p && m <= q && n + m <= p + q - r;
}

int main()
{
	scanf ("%d %d",&n,&m);

	int l = 0, r = 6000000, a = 6000000;
	while (l <= r){
		int mid = (l + r) / 2;
		if (chk(mid)){
			r = mid - 1;
			a = mid;
		}
		else l = mid + 1;
	}
	printf ("%d\n",a);

	return 0;
}