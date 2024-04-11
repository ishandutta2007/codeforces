#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=300010;
int c1[MAXN],c2[MAXN],len1,len2,ans1,ans2;
char s[MAXN],t[MAXN];
bool used[MAXN];
char trans(char c)
{
    if(c>='a'&&c<='z') return c-'a'+'A';
    else return c-'A'+'a';
}
int main()
{
    scanf("%s%s",s,t);
    len1=strlen(s),len2=strlen(t);
    for(int i=0;i<len1;i++) c1[s[i]]++;
    for(int i=0;i<len2;i++) c2[t[i]]++;
    for(int i=0;i<len1;i++)
        if(c2[s[i]]) c2[s[i]]--,ans1++,used[i]=true;
    for(int i=0;i<len1;i++)
        if(!used[i]&&c2[trans(s[i])]) c2[trans(s[i])]--,ans2++;
    printf("%d %d\n",ans1,ans2);
    return 0;
}