#include <cstdio>
#include <cstring>

char s[101000];
char c1[101000], c2[101000];

int main()
{
	scanf("%s", s);
	int len = strlen(s);
	int sum = 0; 
	int cnt1 = 0, cnt2 = 0;
	for(int i = 0; i < len; i++)
	{
		sum += s[i] - '0'; c1[i] = s[i]; c2[i] = s[i];
		if(s[i] == '1' || s[i] == '4' || s[i] == '7') cnt1++;
		if(s[i] == '2' || s[i] == '5' || s[i] == '8') cnt2++;
	}
	if(sum % 3 == 0) printf("%s", s);
	if(sum % 3 == 1)
	{
		bool ok1 = 0, ok2 = 0;
		if(cnt2 >= 2)
		{
			ok1 = 1;
			int u = 0;
			for(int i = len - 1; i >= 0; i--)
			{
				if(u == 2);
				else if(s[i] == '2' || s[i] == '5' || s[i] == '8') u++, c1[i] = '$';
			}
		}
		if(cnt1)
		{
			ok2 = 1;
			bool u = 0;
			for(int i = len - 1; i >= 0; i--)
			{
				if(u);
				else if(s[i] == '1' || s[i] == '4' || s[i] == '7') u++, c2[i] = '$';
			}
		}
		int j = 0; bool fi = 0, okk = 0;
		if(ok1)
		for(int i = 0; i < len; i++)
		{
			if(c1[i] == '$') continue;
			if(c1[i] >= '0' && c1[i] <= '9') okk = 1;
			if(!fi && c1[i] == '0') continue;
			c1[j++] = c1[i]; fi = 1;			
		}
		int len1 = j;
		if(okk && len1 == 0) c1[len1++] = '0';
		
		j = 0; fi = 0, okk = 0;
		if(ok2)
		for(int i = 0; i < len; i++)
		{
			if(c2[i] == '$') continue;
			if(c2[i] >= '0' && c2[i] <= '9') okk = 1;
			if(!fi && c2[i] == '0') continue;
			c2[j++] = c2[i]; fi = 1;			
		}
		int len2 = j;
		if(okk && len2 == 0) c2[len2++] = '0';
		
		if(len1 == 0 && len2 == 0) puts("-1");
		if(len1 > len2)
		{
			for(int i = 0; i < len1; i++) printf("%c", c1[i]);
		}
		else
		{
			for(int i = 0; i < len2; i++) printf("%c", c2[i]);
		}
	}
	if(sum % 3 == 2)
	{
		bool ok1 = 0, ok2 = 0;
		if(cnt1 >= 2)
		{
			ok1 = 1;
			int u = 0;
			for(int i = len - 1; i >= 0; i--)
			{
				if(u == 2);
				else if(s[i] == '1' || s[i] == '4' || s[i] == '7') u++, c1[i] = '$';
			}
		}
		if(cnt2)
		{
			ok2 = 1;
			bool u = 0;
			for(int i = len - 1; i >= 0; i--)
			{
				if(u);
				else if(s[i] == '2' || s[i] == '5' || s[i] == '8') u++, c2[i] = '$';
			}
		}
		int j = 0; bool fi = 0, okk = 0;
		if(ok1)
		for(int i = 0; i < len; i++)
		{
			if(c1[i] == '$') continue;
			if(c1[i] >= '0' && c1[i] <= '9') okk = 1;
			if(!fi && c1[i] == '0') continue;
			c1[j++] = c1[i]; fi = 1;			
		}
		int len1 = j;
		if(okk && len1 == 0) c1[len1++] = '0';
		
		j = 0; fi = 0, okk = 0;
		if(ok2)
		for(int i = 0; i < len; i++)
		{
			if(c2[i] == '$') continue;
			if(c2[i] >= '0' && c2[i] <= '9') okk = 1;
			if(!fi && c2[i] == '0') continue;
			c2[j++] = c2[i]; fi = 1;			
		}
		int len2 = j;
		if(okk && len2 == 0) c2[len2++] = '0';
		
		if(len1 == 0 && len2 == 0) puts("-1");
		if(len1 > len2)
		{
			for(int i = 0; i < len1; i++) printf("%c", c1[i]);
		}
		else
		{
			for(int i = 0; i < len2; i++) printf("%c", c2[i]);
		}
	}
	return 0;
}