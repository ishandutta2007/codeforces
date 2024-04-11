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
vector<int> v;
vector<int> v2;
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n;
    scanf("%d",&n);
    scanf("%s",a);
    int i;
    int stage = 0;
    int cnt = 0;
    for (i=0;i<n;i++)
    {
        if ((stage == 0) && (a[i] == '1'))
        {
            stage ++;
            printf("1");
        }
        else if ((stage == 1) && (a[i] == '0'))
        {
            stage++;
            int j;
            for (j=0;j<i;j++)
            {
                if (a[j] == '1')
                {
                    v.push_back(j);
                }
            }
            printf("1");
        }
        else if ((stage == 1) && (i != n-1))
        {
            printf("1");
        }
        else if ((stage == 2) && (a[i] == '0'))
        {
            cnt++;
            int j;
            v2.clear();
            for (j=0;j<(int)v.size();j++)
            {
                if ((a[v[j]+cnt]) == '1')
                {
                    v2.push_back(v[j]);
                }
            }
            if (v2.size() == 0)
            {
                printf("0");
            }
            else
            {
                v = v2;
                printf("1");
            }
        }
        else if (stage == 2)
        {
            printf("1");
            cnt++;
        }
    }
    if (stage == 0)
    {
        printf("0");
    }
    printf("\n");
    return 0;
}