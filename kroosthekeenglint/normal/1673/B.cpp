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
char a[1000005];
int last_update[155];
bool used[155];
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
        int i;
        for (i='a';i<='z';i++)
        {
            last_update[i]=-1;
            used[i]=false;
        }
        for (i=0;a[i]!='\0';i++)
        {
            used[a[i]]=true;
        }
        for (i=0;a[i]!='\0';i++)
        {
            int j;
            for (j='a';j<='z';j++)
            {
                if (!used[j])
                {
                    continue;
                }
                if (last_update[j]<last_update[a[i]])
                {
                    break;
                }
            }
            last_update[a[i]]=i;
            if (j<='z')
            {
                break;
            }
        }
        if (a[i]=='\0')
        {
            puts("YES");
        }
        else
        {
            puts("NO");
        }
    }
    return 0;
}