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
#define next n128
#define prev p2130
int n;
char a[100005];
char next[128];
bool prev[128];
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
        int n;
        scanf("%d",&n);
        scanf("%s",a);
        int i;
        for (i='a';i<='z';i++)
        {
            next[i] = '\0';
            prev[i] = false;
        }
        for (i=0;i<n;i++)
        {
            if (next[a[i]] != '\0')
            {
                printf("%c", next[a[i]]);
                continue;
            }
            int j;
            for (j=0;j<26;j++)
            {
                if (prev['a'+j])
                {
                    continue;
                }
                next[a[i]] = 'a' + j;
                int cnt = 0;
                int k = 'a' + j;
                for (;;)
                {
                    if (k == '\0')
                    {
                        break;
                    }
                    if (k == a[i])
                    {
                        break;
                    }
                    k = next[k];
                    cnt ++;
                }
                if ((k == '\0') || (cnt == 25))
                {
                    printf("%c", next[a[i]]);
                    prev['a'+j] = true;
                    break;
                }
            }
        }
        printf("\n");
    }
    return 0;
}