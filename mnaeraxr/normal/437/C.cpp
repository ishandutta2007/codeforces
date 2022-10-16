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

bool linked[1005][1005];
int cost[1005];
int value[1005];
int added_cost[1005];
bool chosen[1005];

int main()
{   
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i = 0; i < n; ++i)
        scanf("%d",value + i + 1);
    int a,b;
    for (int i = 0; i < m; ++i)
    {
        scanf("%d%d",&a,&b);
        cost[a] += value[b];
        cost[b] += value[a];
        linked[a][b] = true;
        linked[b][a] = true;

        added_cost[a] += value[a];
        added_cost[b] += value[b];
    }

    int total = 0;

    int cur_pos = 0;
    int cur_value = 0;


    for (int i = 1; i <= n; ++i)
    {           
        int min_pos = -1;
        int min_value = -1000000000;
        //printf("%d\n",cur_pos);
        for (int j = 1; j <= n; ++j)
        {
            if (linked[cur_pos][j])
            {
                //printf("J %d\n",j);
                cost[j] -= value[cur_pos];
                added_cost[j] -= value[j];
            }
            if (!chosen[j])
            {
                //if (cost[j] < min_value)
                if (value[j] > min_value)
                {
                    min_value = value[j];
                    min_pos = j;
                }
                //if (cost[j] == min_value && added_cost[j] >= added_cost[min_pos])
                if (value[j] == min_value && cost[j] > cost[min_pos])
                {
                    min_value = value[j];
                    min_pos = j;    
                }
            }
        }
        //printf("POS %d VALOR %d\n",min_pos,min_value);
        chosen[min_pos] = true;
        total += cost[min_pos];
        cur_pos = min_pos;
    }
    printf("%d\n",total);
    //system("pause");
    return 0;
}

/*
7 10
40 10 20 10 20 80 40
1 5
4 7
4 5
5 2
5 7
6 4
1 6
1 3
4 3
1 4
*/