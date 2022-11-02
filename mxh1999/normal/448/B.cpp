#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<string>
using namespace std;

#define maxn 1010
int ch[30],ch1[30];
char a[maxn],b[maxn];
int n,m;

int main()
{
    memset(ch,0,sizeof(ch));
    scanf("%s",&a);
    n=strlen(a);
    for (int i=0;i<n;i++)
        ch[a[i]-'a'+1]++;
    memset(ch1,0,sizeof(ch1));
    scanf("%s",&b);
    m=strlen(b);
    for (int i=0;i<m;i++)
        ch1[b[i]-'a'+1]++;
    bool flag=true;
    bool flag1=true;
    for (int i=1;i<=26;i++)
    {
        if (ch[i]!=ch1[i])  flag1=false;
        if (ch[i]<ch1[i])   flag=false;
    }
    if (flag1==false && flag==false)    {cout<<"need tree"<<endl;return 0;}
    if (flag1==true)    {cout<<"array"<<endl;return 0;}
    int i=0,j=0;
    while (i<m)
    {
        if (j==n) break;
        if (a[j]==b[i]) {i++;j++;} else j++;
    }
    if (i==m)   cout<<"automaton"<<endl; else cout<<"both"<<endl;
    return 0;
}