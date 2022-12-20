#include<bits/stdc++.h>
using namespace std;

priority_queue<int> in[50];

map<int,int> to_pop;

long long sum[50];

int get_group(int cur)
{
    int ret=0;

    while(cur)
    {
        ret++;
        cur=cur/2;
    }

    return ret;
}

int active=0;

void update(int cur)
{
    int where=get_group(cur);

    sum[where]+=cur;

    in[where].push(-cur);

    active++;
}

void my_pop(int cur)
{
    int where=get_group(cur);

    sum[where]-=cur;

    to_pop[cur]++;

    while(to_pop[-in[where].top()])
    {
        to_pop[-in[where].top()]--;
        in[where].pop();
    }

    active--;
}

int query()
{
    int ret=active;

    long long cur_sum=0;

    for(int i=0;i<35;i++)
        if(in[i].size())
        {
            if(2*cur_sum<-in[i].top())ret--;

            cur_sum+=sum[i];
        }
    return ret;
}

int main()
{
    int q;
    scanf("%i",&q);

    for(int i=1;i<=q;i++)
    {
        char c=getchar();

        while(c!='+'&&c!='-')c=getchar();

        if(c=='+')
        {
            int cur;
            scanf("%i",&cur);
            update(cur);
        }
        else
        {
            int cur;
            scanf("%i",&cur);
            my_pop(cur);
        }

        printf("%i\n",query());
    }

    return 0;
}