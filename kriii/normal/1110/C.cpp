#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
	int T; scanf ("%d",&T); while (T--){
		int a; scanf ("%d",&a);
		if (a == 3) puts("1");
		else if (a == 7) puts("1");
		else if (a == 15) puts("5");
		else if (a == 31) puts("1");
		else if (a == 63) puts("21");
		else if (a == 127) puts("1");
		else if (a == 255) puts("85");
		else if (a == 511) puts("73");
		else if (a == 1023) puts("341");
		else if (a == 2047) puts("89");
		else if (a == 4095) puts("1365");
		else if (a == 8191) puts("1");
		else if (a == 16383) puts("5461");
		else if (a == 32767) puts("4681");
		else if (a == 65535) puts("21845");
		else if (a == 131071) puts("1");
		else if (a == 262143) puts("87381");
		else if (a == 524287) puts("1");
		else if (a == 1048575) puts("349525");
		else if (a == 2097151) puts("299593");
		else if (a == 4194303) puts("1398101");
		else if (a == 8388607) puts("178481");
		else if (a == 16777215) puts("5592405");
		else if (a == 33554431) puts("1082401");
		else{
			int r = 1;
			while (r <= a) r *= 2;
			printf ("%d\n",r-1);
		}
	}

	return 0;
}