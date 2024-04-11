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
#define next n12893
char s[1000015];
int fail[1000015];
int next[1000015][26];
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    scanf("%s",s);
    int n = strlen(s);
    int i;
    fail[0] = 0;
    for (i=0;i<n;i++)
    {
        int j;
        for (j=0;j<26;j++)
        {
            next[i][j] = next[fail[i]][j];
        }
        next[i][s[i]-'a'] = i+1;
        if (i!=0)
        {
            fail[i+1] = next[fail[i]][s[i]-'a'];
        }
        else
        {
            fail[i+1] = 0;
        }
    }
    int q;
    scanf("%d",&q);
    int tt;
    for (tt=0;tt<q;tt++)
    {
        scanf("%s",s+n);
        for (i=n;s[i]!='\0';i++)
        {
            int j;
            for (j=0;j<26;j++)
            {
                next[i][j] = next[fail[i]][j];
            }
            next[i][s[i]-'a'] = i+1;
            fail[i+1] = next[fail[i]][s[i]-'a'];
            printf("%d ",fail[i+1]);
        }
        printf("\n");
    }
    return 0;
}