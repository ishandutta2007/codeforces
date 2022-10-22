#include<set>
#include<map>
#include<list>
#include<queue>
#include<stack>
#include<string>
#include<math.h>
#include<time.h>
#include<vector>
#include<bitset>
#include<memory>
#include<utility>
#include<fstream>
#include<stdio.h>
#include<sstream>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
char a[200005];
bool valid(string x)
{
    int cnt=0;
    int i;
    for (i=0;i<x.length();i++)
    {
        if (x[i]=='(')
        {
            cnt++;
        }
        else
        {
            cnt--;
        }
        if (cnt<0)
        {
            return false;
        }
    }
    return cnt==0;
}
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int t;
    scanf("%d",&t);
    int zu;
    for (zu=0;zu<t;zu++)
    {
        scanf("%s",a);
        int n = strlen(a)/2;
        int i;
        string b = a;
        string c = a;
        int cnt=0;
        for (i=0;i<n+n;i++)
        {
            if (a[i]=='(')
            {
                cnt++;
            }
        }
        cnt=n-cnt;
        bool tag = true;
        for (i=0;i<n+n;i++)
        {
            if (a[i]=='?')
            {
                tag = false;
                cnt--;
                if (cnt>0)
                {
                    b[i]='(';
                    c[i]='(';
                }
                else if (cnt==0)
                {
                    b[i]='(';
                    c[i]=')';
                }
                else if (cnt==-1)
                {
                    b[i]=')';
                    c[i]='(';
                }
                else
                {
                    b[i]=')';
                    c[i]=')';
                }
            }
        }
        if (tag)
        {
            if (valid(b))
            {
                puts("YES");
            }
            else
            {
                puts("NO");
            }
        }
        else
        {
            if ((valid(b))&&(!valid(c)))
            {
                puts("YES");
            }
            else
            {
                puts("NO");
            }
        }
    }
    return 0;
}