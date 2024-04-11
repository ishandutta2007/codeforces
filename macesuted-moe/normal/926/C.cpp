#include <cstdio>

int a[100005];

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",a+i);
	int length;
	int point=0;
	while(point<n&&a[point]==a[0]) point++;
	length=point;
	if(n%length!=0)
	{
		puts("NO");
		return 0;
	}
	int color=!a[0];
	while(point<n)
	{
		for(int i=0;i<length;i++)
			if(a[point++]!=color)
			{
				puts("NO");
				return 0;
			}
		color=!color;
	}
	puts("YES");
	return 0;
}