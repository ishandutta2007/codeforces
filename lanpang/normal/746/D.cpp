#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

int n , k , a , b;
int l , s;
char f[100001] , c;

int main ()
{
	int i;
	scanf("%d%d%d%d",&n,&k,&a,&b);     
	for (i = 1 ; i <= n ; i++)
	{
		if (s == k)
		{
			if (c == 'G')
			{
				if (b == 0)
					break;
				else
				{
					b--;
					f[i] = 'B';
					c = 'B';
					s = 1;
				}
			}
			else
			{
			    if (a == 0)
					break;
				else
				{
					a--;
					f[i] = 'G';
					c = 'G';
					s = 1;
				}
			}
		}
		else
		{
			if (a == b)
			{
				if (c == 'G')
				{
					b--;
					f[i] = 'B';
					c = 'B';
					s = 1;
				}
				else
				{
					a--;
					f[i] = 'G';
					c = 'G';
					s = 1;
				}
			}
			else
			{
				if (a > b)
				{
					a--;
					f[i] = 'G';
					if (c == 'G')
					    s++;
					else
					{
						s = 1;
						c = 'G';
					}    
				}
				else
				{
					b--;
					f[i] = 'B';
					if (c == 'B')
					    s++;
					else
					{
						s = 1;
						c = 'B';
					}    
				}
			}
		}
	}
	if (i <= n)
	    cout << "NO\n";
	else
	{
		for (i = 1 ; i <= n ; i++)
		    printf("%c",f[i]);
		cout << "\n";    
	}
    //system("PAUSE");
	return 0;
}