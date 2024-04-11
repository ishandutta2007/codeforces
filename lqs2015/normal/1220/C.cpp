#include<bits/stdc++.h>
using namespace std;
int n,mn;
char s[555555];
int main()
{
    scanf("%s",s);
    n=strlen(s);mn=1e9;
    for (int i=0;i<n;i++)
    {
        if (s[i]-'a'<=mn) printf("Mike\n");
        else printf("Ann\n");
        mn=min(mn,s[i]-'a');
    }
    return 0;
}