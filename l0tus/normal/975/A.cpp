#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define M 1000
int script[1000];
int main()
{
    int n,i,j,num=0,sum=0;
    char str[M+1];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        int word[26]={};
        scanf("%s",str);
        for(j=0;j<strlen(str);j++)
            word[str[j]-'a']=1;
        for(j=0;j<26;j++)
            if(word[j])
                script[i]+=(1<<j);
    }
    sort(script,script+n);
    for(i=0;i<n;i++)
        if(script[i]>num)
        {
            num=script[i];
            sum++;
        }
    printf("%d",sum);
}