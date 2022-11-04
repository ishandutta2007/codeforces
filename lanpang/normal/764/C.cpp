#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

int top=1 , adj[200001] , next1[400001] , to[400001];
int n , a[200001] , t[200001] , p=0 , k , f=0 , c=0 , h;

void list1(int x , int y)
{
	next1[top] = adj[x];
	next1[top+1] = adj[y];
	to[top] = y;
	to[top+1] = x;
	adj[x] = top;
	adj[y] = top+1;
	top += 2;
}

int main ()
{
	int i , j , x , y;
	scanf("%d",&n);
	for (i = 1 ; i <= n ; i++)
	{
	    t[i] = 0;
	    adj[i] = 0;
	}
	for (i = 1 ; i < n ; i++)
	{
	    scanf("%d%d",&x,&y);
	    list1(x,y);
	}
	for (i = 1 ; i <= n ; i++)
		scanf("%d",&a[i]);
	for (i = 1 ; i <= n ; i++)
	{
		for (j = adj[i] ; j != 0 ; j = next1[j])
		{
			if (i < to[j] && a[i] != a[to[j]])
			{
				t[i]++;
				t[to[j]]++;
			}
		}
	} 
	for (i = 1 ; i <= n ; i++)
	{
		if (t[i] >= 2)
		{
		    p++;
		    k = i;
		}
		if (t[i] == 1)
		{
		    c++;
		    h = i;
		}
	}
	if (p == 1)
	{
		for (i = adj[k] ; i != 0 ; i = next1[i])
			if (a[k] != a[to[i]])
				f++;
		if (c == f)		
	        printf("YES\n%d\n",k);
	    else
		    printf("NO\n");   
	}
	else
	{
		if (p >= 2)
		    printf("NO\n");
		else
		{
			if (c == 0)
			    printf("YES\n1\n");
			else
			{
				if (c == 2)
				    printf("YES\n%d\n",h);
				else
				    printf("NO\n");    
			}
		}    
	}    
    //system("PAUSE");
	return 0;
}