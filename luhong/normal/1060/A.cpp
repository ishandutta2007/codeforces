#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int cnt; 
char s[110];
int main()
{
	int n; scanf("%d", &n);
	scanf("%s", s + 1);
	for(int i = 1; i <= n; i++) if(s[i] == '8') cnt++;
	printf("%d\n", min(n/ 11, cnt));
	return 0;
}