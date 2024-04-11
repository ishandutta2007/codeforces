#include<bits/stdc++.h>
using namespace std;

long long i,j,k,l,counti,day,lift,diff;
const int arr = 1e5+10;
long long costi[arr];
long long weight[arr];
priority_queue<long long> cost;

int main()
{
    scanf("%lld %lld",&day,&lift);
    for(i=0;i<day;i++)
        scanf("%lld",&weight[i]);
    scanf("%lld",&diff);
    for(i=0;i<day;i++)
    {
        scanf("%lld",&l);
        cost.push(-l);
        if(lift < weight[i])
        {
            while(!cost.empty() && lift < weight[i])
            {
                counti+=-cost.top();
                cost.pop();
                lift+=diff;
            }
            if(cost.empty() && lift < weight[i])
            {
                j=1;
                break;
            }
        }
    }
    if(j)
    {
        printf("-1");
    }
    else
    {
        printf("%lld",counti);
    }
    return 0;
}