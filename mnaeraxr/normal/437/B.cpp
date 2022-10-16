// author       : MarX
// copyright    : UH

#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <complex>
#include <algorithm>

using namespace std;

#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()using namespace std;
#define DB(x) cerr << __LINE__ << ": " << #x << " = " << x << endl;

int pow_2[20];
bool taken[100005];

int max_pow(int n)
{
    int p = 1;
    while (p <= n)
    {
        p *= 2;
    }
    return p/2;
}

int list[100005];

int main()
{   
    int sum, limit;
    scanf("%d%d",&sum,&limit);

    int value = 0;

    int mpow = max_pow(sum);
    int counter = 0;
    while (value < sum && mpow > 0)
    {
        int add = mpow;
        while (value + mpow <= sum && add <= limit)
        {
            //printf("VALUE %d POW %d SUM %d ADD %d LIMIT %d\n", value, mpow, sum, add,limit);
            if (!taken[add])
            {
                //printf("ADD %d\n",add);
                list[counter++] = add;
                taken[add] = true;
                value += mpow;
                if (value == sum)
                    break;
            }
            add += mpow;
        }
        mpow /= 2;
        //printf("POW %d\n",mpow);
    }
    if (value == sum)
    {
        printf("%d\n",counter);
        printf("%d",list[0]);
        for (int i = 1; i < counter; ++i)
            printf(" %d",list[i]);
        printf("\n");
    }
    else
    {
        printf("-1\n");
    }
    //system("pause");
    
    return 0;
}