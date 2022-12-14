#include <stdio.h>
int main()
{
	int n, t, bigger_cons, smaller_cons, i;
	char str1[10], str2[10];
	bool sequ, bequ;
	scanf("%d", &n);
	bigger_cons = -2000000000;
	bequ = true;
	smaller_cons = 2000000000;
	sequ = true;
	for(i = 1; i <= n; i ++)
	{
		scanf("%s%d%s", str1, &t, str2);
		if(str1[0] == '<')
		{
			if(str1[1] == '=')
			{
				if(str2[0] == 'Y')//<=
				{
					if(t < smaller_cons)
					{
						smaller_cons = t;
						sequ = true;
					}
				}
				else//>
					if(t > bigger_cons)
					{
						bigger_cons = t;
						bequ = false;
					}
					else if(t == bigger_cons)
						bequ = false;
			}
			else
			{
				if(str2[0] == 'Y')//<
				{
					if(t < smaller_cons)
					{
						smaller_cons = t;
						sequ = false;
					}
					else if(t == smaller_cons)
						sequ = false;
				}
				else//>=
				{
					if(t > bigger_cons)
					{
						bigger_cons = t;
						bequ = true;
					}
				}
			}
		}
		else
		{
			if(str1[1] == '=')
			{
				if(str2[0] == 'Y')//>=
				{
					if(t > bigger_cons)
					{
						bigger_cons = t;
						bequ = true;
					}
				}
				else//<
					if(t < smaller_cons)
					{
						smaller_cons = t;
						sequ = false;
					}
					else if(t == smaller_cons)
						sequ = false;
			}
			else
			{
				if(str2[0] == 'Y')//>
				{
					if(t > bigger_cons)
					{
						bigger_cons = t;
						bequ = false;
					}
					else if(t == bigger_cons)
						bequ = false;
				}
				else//<=
				{
					if(t < smaller_cons)
					{
						smaller_cons = t;
						sequ = true;
					}
				}
			}
		}
	}
	if(!sequ)
		smaller_cons --;
	if(!bequ)
		bigger_cons ++;
	if(smaller_cons >= bigger_cons)
		printf("%d\n", bigger_cons);
	else
		printf("Impossible\n");
	return 0;
}