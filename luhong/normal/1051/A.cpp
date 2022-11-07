#include <cstdio>
#include <cstring> 

bool used[3];
void check(char *s, int l, int r)
{
	for(int i = l; i <= r; i++)
	{
		if(s[i] >= '0' && s[i] <= '9') used[0] = 1;
		if(s[i] >= 'a' && s[i] <= 'z') used[1] = 1;
		if(s[i] >= 'A' && s[i] <= 'Z') used[2] = 1;
	}
}
int main()
{
	int T; scanf("%d", &T); 
	while(T--)
	{
		char s[111]; scanf("%s", s);
		int len = strlen(s);
		used[0] = used[1] = used[2] = 0;
		check(s, 0, len - 1);
		if(used[0]&used[1]&used[2]) {printf("%s\n", s);continue;}
		for(int i = 1; i <= len; i++)
		{
			int ok = 0;
			for(int j = 0; j + i - 1 < len; j++)
			{
				used[0] = used[1] = used[2] = 0;
				int k = j + i - 1;
				check(s, 0, j - 1); check(s, k + 1, len - 1);
				int sum = 0;
				if(used[0] == 0) sum++;
				if(used[1] == 0) sum++;
				if(used[2] == 0) sum++;
				if(sum <= i)
				{
					for(int l = 0; l <= j - 1; l++) printf("%c", s[l]);
					if(used[0] == 0) printf("1");
					if(used[1] == 0) printf("a");
					if(used[2] == 0) printf("A");
					for(int l = k + 1; l <= len - 1; l++) printf("%c", s[l]);
					ok = 1; break;
				}
			}
			if(ok) break;
		}
		puts("");
	}
	return 0;
}