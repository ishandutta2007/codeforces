#include <cstdio>
#include <iostream>

char s[110];
int main()
{
	int T; scanf("%d", &T); 
	while(T--)
	{
		int n; scanf("%d", &n);
		scanf("%s", s);
		bool ok = 0;
		for(int i = 0; i < n; i++)
			if(s[i] == '8' && n - i >= 11) {puts("YES"); ok = 1; break;}
		if(!ok) puts("NO");
	}
}