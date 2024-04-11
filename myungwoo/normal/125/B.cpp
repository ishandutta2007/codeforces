#include <stdio.h>
#include <string.h>

int N;
char buf[1004];

int dfs(int s,int dep)
{
    int i;
    for (i=0;i<dep+dep;i++) printf(" ");
    printf("<%c>\n",buf[s+1]);
    for (s=s+3;s<N&&buf[s+1]!='/';s=dfs(s,dep+1));
    for (i=0;i<dep+dep;i++) printf(" ");
    printf("</%c>\n",buf[s+2]);
    return s+4;
}

int main()
{
    scanf("%s",buf); N = strlen(buf);
    for (int s=0;s<N;s=dfs(s,0));
}