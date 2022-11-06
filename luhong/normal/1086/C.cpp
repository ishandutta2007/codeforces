#include <cstdio>
#include <cstring>

char a[1010000], b[1010000], s[1010000];
bool used[27];
char ans[27]; 
int k;

bool solve(int type)
{
	int len = strlen(a);
	for(int i = 0; i < 26; i++) ans[i] = '@';
	memset(used, 0, sizeof(used));
	bool ok1 = 0, ok2 = 0;
	for(int i = 0; i < len; i++)
	{
		if(ans[s[i] - 'a'] != '@')
		{
			bool ok3 = ok1, ok4 = ok2;
			if(ans[s[i] - 'a'] > a[i]) ok3 = ok1 = 1;
			if(ans[s[i] - 'a'] == a[i]) ok3 = 1;
			if(ans[s[i] - 'a'] < b[i]) ok4 = ok2 = 1;
			if(ans[s[i] - 'a'] == b[i]) ok4 = 1;
			if(!ok3 || !ok4) return 0;
			continue;
		}
		bool okk = 0;
		if(!ok1 && !ok2)
		{
			for(int j = a[i] - 'a' + 1; j < b[i] - 'a'; j++)
			{
				if(!used[j])
				{
					ans[s[i] - 'a'] = j + 'a';
					used[j] = 1;
					ok1 = ok2 = 1;
					okk = 1;
					break;
				}
			}
			if(okk) break; 
			if(a[i] == b[i])
			{
				if(used[a[i] - 'a']) return 0;
				ans[s[i] - 'a'] = a[i];
				used[a[i] - 'a'] = 1;
			}
			else
			{
				if(used[a[i] - 'a'] && used[b[i] - 'a']) return 0;
				if(used[a[i] - 'a']) ans[s[i] - 'a'] = b[i], used[b[i] - 'a'] = 1, ok1 = 1;
				else if(used[b[i] - 'a']) ans[s[i] - 'a'] = a[i], used[a[i] - 'a'] = 1, ok2 = 1;
				else
				{
					if(type == 0) ans[s[i] - 'a'] = a[i], used[a[i] - 'a'] = 1, ok2 = 1;
					else ans[s[i] - 'a'] = b[i], used[b[i] - 'a'] = 1, ok1 = 1;
				}
			}
		}
		else if(!ok1)
		{
			for(int j = a[i] - 'a' + 1; j < k; j++)
			{
				if(!used[j])
				{
					ans[s[i] - 'a'] = j + 'a';
					used[j] = 1;
					ok1 = 1;
					okk = 1;
					break;
				}
			}
			if(okk) break; 
			if(used[a[i] - 'a']) return 0;
			ans[s[i] - 'a'] = a[i];
			used[a[i] - 'a'] = 1;
		}
		else if(!ok2)
		{
			for(int j = 0; j < b[i] - 'a'; j++)
			{
				if(!used[j])
				{
					ans[s[i] - 'a'] = j + 'a';
					used[j] = 1;
					ok2 = 1;
					okk = 1;
					break;
				}
			}
			if(okk) break; 
			if(used[b[i] - 'a']) return 0;
			ans[s[i] - 'a'] = b[i];
			used[b[i] - 'a'] = 1;
		}
	}
	return 1;
}

int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &k);
		scanf("%s%s%s", s, a, b);
		if(solve(0))
		{
			for(int i = 0; i < k; i++)
			{
				if(ans[i] == '@')
				{
					for(int j = 0; j < k; j++)
					{
						if(!used[j])
						{
							used[j] = 1;
							ans[i] = j + 'a';
							break;
						}
					}
				}
			}
			puts("YES");
			for(int i = 0; i < k; i++) printf("%c", ans[i]);
			puts("");
		}
		else if(solve(1))
		{
			for(int i = 0; i < k; i++)
			{
				if(ans[i] == '@')
				{
					for(int j = 0; j < k; j++)
					{
						if(!used[j])
						{
							used[j] = 1;
							ans[i] = j + 'a';
							break;
						}
					}
				}
			}
			puts("YES");
			for(int i = 0; i < k; i++) printf("%c", ans[i]);
			puts("");
		}
		else puts("NO");
	}
}