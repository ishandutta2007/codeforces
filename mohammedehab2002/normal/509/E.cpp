#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
int main()
{
    string s;
    long long arr[1000005],i,m=0,ans=0,p;
    double res=0.0;
    cin >> s;
    p=s.size();
    for (i=0;i<s.size();i++)
    {
        if (s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U' || s[i]=='Y')
        m++;
        arr[i+1]=m;
    }
    for (i=1;i<=s.size();i++)
    {
        ans+=arr[p]-arr[i-1];
        res+=(double)ans/(double)i;
        p--;
    }
    printf("%9.7f",res);
}