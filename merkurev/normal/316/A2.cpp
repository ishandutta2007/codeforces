#include <iostream>
#include <string>
#include <cstring>
using namespace std;



char s[100500];
bool used[11];
bool firstLetter;


int main()
{
	scanf("%s", s);
	int len = strlen(s);

	int diffLetters = 0;
	for (int i = 0; i < 11; i++)
		used[i] = false;
		
	
	long long ans = 1;
		
	int tenDegree = 0;
		
	if (s[0] == '?')
		ans = 9;
	else
	{
		for (int i = 0; i < 10; i++)
			if (s[0] - 'A' == i)
			{
				firstLetter = true;
				used[i] = true;
			}
	}
	for (int i = 1; i < len; i++)
	{
		if (s[i] == '?')
		{
			tenDegree++;
			//ans = ans.multiply(BigInteger.TEN);
		}
		else
		{
			for (int j = 0; j < 10; j++)
				if (s[i] - 'A' == j)
				{
					if (used[j] == true)
						continue;
					diffLetters++;
					used[j] = true;
				}
		}
	}
		
	
		
	int rem = 10;
	if (firstLetter)
	{
		rem--;
		ans *= 9;
	}
	for (int i = 0; i < diffLetters; i++)
	{
		ans *= rem;
		rem--;
	}
	printf("%I64d", ans);
	for (int i = 0; i < tenDegree; i++)
		printf("0");




	return 0;
}