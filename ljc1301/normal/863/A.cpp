#include <cstdio>
#include <cstring>
int main()
{
    char str[100];
    int len,i;
    scanf("%s",str); len=strlen(str);
    while(len && str[len-1]=='0') len--;
    for(i=0;i<len;i++)
        if(str[i]!=str[len-i-1])
        {
            printf("NO\n");
            return 0;
        }
    printf("YES\n");
    return 0;
}