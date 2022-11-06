    #include <bits/stdc++.h>
    using namespace std;
    int a[10010];
    int main()
    {
    	int T;
    	scanf("%d", &T);
    	while(T --)
    	{
    		int n;
    		scanf("%d", &n);
    		int mx = 0;
    		for(int i = 1; i <= n; i ++)
    			scanf("%d", a + i);
    		
    		for(int i = 1; i <= n; i ++)
    		{
    			if(i > 1) mx = max(mx, a[i] - a[1]);
    			if(i < n) mx = max(mx, a[n] - a[i]), mx = max(mx, a[i] - a[i + 1]);
    			else mx = max(mx, a[i] - a[1]);
    		}
    		printf("%d\n", mx);
    	}
     
    	return 0;
    }