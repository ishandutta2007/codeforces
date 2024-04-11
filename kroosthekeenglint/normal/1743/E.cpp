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
int p1,p2;
long long t1,t2;
int h;
int def;
long long dp[5005];
long long try_hit(int left_hp)
{
    if (left_hp <= 0)
    {
        return 0;
    }
    if (dp[left_hp] != -1)
    {
        return dp[left_hp];
    }
    long long load_1 = t1;
    long long load_2 = t2;
    long long sum_time = 0;
    long long best_ans = 1000000000000000000ll;
    int current_damage = 0;
    for (;;)
    {
        if (load_1 > load_2)
        {
            load_1 -= load_2;
            sum_time += load_2;
            load_2 = 0;
        }
        else
        {
            load_2 -= load_1;
            sum_time += load_1;
            load_1 = 0;
        }
        //Solution 1: Hit together.
        int extra_damage = p1 + p2 - def;
        best_ans = min(best_ans, try_hit(left_hp - current_damage - extra_damage) + max(load_1, load_2) + sum_time);
        
        //Solution 2: Hit directly
        if (load_1 == 0)
        {
            current_damage += p1 - def;
            load_1 = t1;
        }
        else
        {
            current_damage += p2 - def;
            load_2 = t2;
        }
        if (current_damage >= left_hp)
        {
            best_ans = min(best_ans, sum_time);
            break;
        } 
    }
    dp[left_hp] = best_ans;
    return best_ans;
}
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    memset(dp,-1,sizeof(dp));
    scanf("%d%lld",&p1,&t1);
    scanf("%d%lld",&p2,&t2);
    scanf("%d%d",&h,&def);
    printf("%lld\n",try_hit(h));
    return 0;
}