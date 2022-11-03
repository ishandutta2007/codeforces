#include <bits/stdc++.h>
using namespace std;
char s[100];
int main()
{
    int i;
    s[2]='\0'; scanf("%s",s);
    for(i=2;s[i];i++)
        if((s[i]-'A')!=((int)(s[i-1]-'A')+(int)(s[i-2]-'A'))%26)
        {
            printf("NO\n");
            return 0;
        }
    printf("YES\n");
    return 0;
}