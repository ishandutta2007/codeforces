#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n;
string str;
int main()
{
    cin>>str;
    n=str.length();
    for(int i=0;i<=n;i++)
        for(int j=i;j<=n;j++)
            if(str.substr(0,i)+str.substr(j)=="CODEFORCES") {puts("YES");return 0;}
    puts("NO");
    return 0;
}