#include<cstdio>
#include<iostream>
#include<algorithm>
#include<memory.h>
#include<cstring>
#define inf 0x3fffffff
#define N 100005
using namespace std;
char s[N];
int i,len;
bool f;
int main()
{
    scanf("%s",s + 1);
    f = false;
	len = strlen(s + 1);
    for(int i = 1; i < len - 2; i ++) 
        if (s[i] == 'A' && s[i + 1] == 'B')
        {
			for(int j = i + 2; j <= len; j ++)
				if(s[j] == 'B' && s[j + 1] == 'A') f = true;
            break;
        }
    for (int i = 1; i < len - 2; i ++) 
        if (s[i] == 'B' && s[i + 1] == 'A')
        {
            for (int j = i + 2; j < len; j ++) 
				if (s[j] == 'A' && s[j + 1] == 'B') f = true;
            break;
        }
    if (f) printf("YES\n");
	else printf("NO\n");
	return 0;
}