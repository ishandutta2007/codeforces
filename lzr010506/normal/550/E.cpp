#include<cstdio>
#include<iostream>
#include<algorithm>
#include<memory.h>
#include<cstring>
#define inf 0x3fffffff
#define N 100005
using namespace std;
int n,last,l2,l3,a[N];
int main()
{
    scanf("%d",&n);
    for (int i = 1; i <= n; i ++)
		scanf("%d",&a[i]);  
    last = 1;
	l2 = 0;
    for(int i = n; i; i --) 
		if (a[i]) 
		{
			last = i + 1;
			break;
		}
    for(int i = last - 1; i; i --) 
		if(!a[i])
		{
			l2 = i;
			break;
		}
    int cnt = n - last + 1;
    if (a[n] == 1 || (cnt == 2 && l2 == 0))
	{
		printf("NO\n");
		return 0;
	}
    printf("YES\n");
    if (l2)
		for (int i = l2; i; i --)
			if (!a[i]) l3 = i;
			else break;
    int cnt2 = cnt + l2 - l3 + 1;
    if(cnt == 2)
        if(cnt2 % 2 == 1) 
        {
            for(int i = 1; i <= l2; i ++)
				printf("%d->",a[i]);
            printf("(");
            for(int i = l2 + 1; i < last; i ++) 
				printf("%d->",a[i]);
            printf("0)->0");
            return 0;
        }
        else
        {
            for (int i = 1; i < l2; i ++)
				printf("%d->",a[i]);
            printf("(0->");
            printf("(");
            for (int i = l2 + 1; i < last; i ++) 
				printf("%d->",a[i]);
            printf("0))->0");
            return 0;
        }
    
    if (cnt % 2 == 1)
    {
        for (int i = 1; i < n; i ++)
			printf("%d->",a[i]);
		printf("%d",a[n]);
    }
    else
    {
        for (int i = 1; i < n - 2; i ++) 
			printf("%d->",a[i]);
        printf("(%d->%d)->%d", a[n - 2], a[n - 1], a[n]);
    }
    return 0;
}