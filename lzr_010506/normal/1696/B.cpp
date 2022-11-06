#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10; 
int a[N];
 
int main()
{
	int T;
	scanf("%d", &T);
    while(T --)
	{
		int n;
        scanf("%d", &n);
        for(int i = 1; i <= n; i ++) scanf("%d", a + i);
        bool flag = 1;
        for(int i = 1; i <= n; i ++)
			if(a[i]) flag = 0;
        if(flag)
		{
			puts("0");
            continue;
        }
        bool flag1 = 0, flag2 = 0, tag = 1;
        for(int i = 1; i <= n; i ++)
		{
            if(flag1 == 0 && a[i]) flag1 = 1;
            if(flag1 && flag2 == 0 && a[i] == 0) flag2 = 1;
            if(flag2 && a[i]) tag = 0;
        }
        if(tag) puts("1");
        else puts("2");
    }
    return 0;
}