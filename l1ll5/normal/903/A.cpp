
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T,n;
    scanf("%d",&T);
	while(T--)
    {
        scanf("%d",&n);
		bool flag = false;
        for (int i = 0; i <= 100; i++)
        {
        	for (int j = 0; j <= 100; j++)
        	{
        		if (i * 3 + j * 7 == n) flag = true;
			}
		}
        if (flag) puts("YES"); else puts("NO");
    }
    return 0;
}