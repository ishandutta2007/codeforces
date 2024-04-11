#include<stdio.h>
#include<string.h>
#include<algorithm>
int main(void)
{
    char a[1005],b[1005],c[1005],d[1005],e[1005];
    int wrong=0;
    scanf("%s%s%s",&a,&b,&c);
    strcpy(d,a);
    strcat(d,b);
    if(strlen(d)!=strlen(c)) printf("NO");
    else
    {
    for(int i=0;i<strlen(d);i++)
    {
        for(int j=0;j<strlen(c);j++)
        {
            if(c[j]==d[i])
            {
                e[i]=d[i];
                c[j]='0';
                break;
            }
        }
    }
    for(int k=0;k<strlen(c);k++) if(c[k]!='0') wrong=1;
    if(wrong==0) printf("YES");
    else printf("NO");
    
    }
}