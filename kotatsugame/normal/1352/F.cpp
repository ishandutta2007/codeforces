#include<cstdio>
using namespace std;
int T;
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		if(b==0)
		{
			if(a)putchar('0');
			for(;a--;)putchar('0');
			if(c)putchar('1');
			for(;c--;)putchar('1');
			puts("");
			continue;
		}
		putchar('0');
		for(;a--;)putchar('0');
		putchar('1');
		b--;
		for(;c--;)putchar('1');
		for(int i=0;i<b;i++)putchar('0'+i%2);
		puts("");
	}
}