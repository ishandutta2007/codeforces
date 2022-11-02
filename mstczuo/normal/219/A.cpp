#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
int a[26], k;
string s;
bool flag=true;
int main()
{
    scanf("%d",&k);
    getline(cin,s);
    getline(cin,s);
    for(int i=0;i<s.length();i++)a[s[i]-'a']++;
    for(int i=0;i<26;i++)if(a[i]%k)flag=false;
    if(!flag){cout<<-1;return 0;}
    for(int t=0;t<k;t++)
    for(int i=0;i<26;i++)
    for(int j=a[i]/k;j;j--)
    printf("%c",'a'+i);
}