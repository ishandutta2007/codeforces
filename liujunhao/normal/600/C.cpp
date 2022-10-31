#include<cstdio>
#include<cstring>
#define MAXN 200000
char s[MAXN+10];
int n,a[100];
int main()
{
    int i,j,t;
    scanf("%s",s);
    n=strlen(s);
    for(i=0;i<n;i++)
        a[s[i]-'a']++;
    i=0,j=25;
    while(i<j){
        while(!(a[i]&1)&&i<j)
            i++;
        if(i==j)
            break;
        while(!(a[j]&1)&&i<j)
            j--;
        if(i==j)
            break;
        a[i]++,a[j]--;
    }
    if(a[i]&1)
        t=i;
    else
        t=100;
    for(i=0;i<26;i++)
        for(j=1,a[i]/=2;j<=a[i];j++)
                printf("%c",i+'a');
    if(t!=100)
        printf("%c",t+'a');
    for(i=25;i>=0;i--)
        for(j=1;j<=a[i];j++)
                printf("%c",i+'a');
}