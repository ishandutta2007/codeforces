#include <cmath>
#include <queue>
#include <cstdio>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 100000
#define ll long long
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
char s[N];
int main()
{
    int n;
    cin>>s;
    n=strlen(s);
    if(s[0]>='a'&&s[0]<='z')
    {
        s[0]=s[0]-'a'+'A';
    }
    cout<<s<<endl;
}