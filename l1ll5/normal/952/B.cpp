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
string s;
char hh[155];
int main()
{
    for (int i=0;i<10;i++)
    {
        printf("%d\n", i);
        fflush(stdout);
        gets(hh);
        s=string(hh);
        if (s=="no") continue;
        int pd=-1;
        if (s=="great"){ pd = 0;}
        else if (s=="don't think so") pd = 0;
        else if (s=="don't touch me") pd = 0;
        else if (s=="not bad") pd = 0;
        else if (s=="cool") pd = 0;
        else if (s=="no way") pd = 1;
        else if (s=="don't even") pd = 1;
        else if (s=="are you serious") pd = 1;
        else if (s=="go die in a hole") pd = 1;
        else if (s=="worse") pd = 1;
        else if (s=="terrible") pd = 1;

        if (pd==-1) continue;
        if (pd==1) printf("grumpy\n");
        else printf("normal\n");
        break;
    }
}