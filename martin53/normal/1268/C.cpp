#include<bits/stdc++.h>
using namespace std;
const int nmax=1e6+42;
int n,inp[nmax];

long long output[nmax];

int fenwick_count[nmax];
long long fenwick_sum[nmax];

void update_count(int pos)
{
    while(pos<=n)
    {
        fenwick_count[pos]++;
        pos=pos+(pos&(-pos));
    }
}

void update_sum(int pos,int val)
{
    while(pos<=n)
    {
        fenwick_sum[pos]+=val;
        pos=pos+(pos&(-pos));
    }
}
int query_count(int pos)
{
    int ret=0;
    while(pos)
    {
        ret=ret+fenwick_count[pos];
        pos=pos-(pos&(-pos));
    }
    return ret;
}
int sum_count(int l,int r)
{
    return query_count(r)-query_count(l-1);
}

long long query_sum(int pos)
{
    long long ret=0;
    while(pos)
    {
        ret=ret+fenwick_sum[pos];
        pos=pos-(pos&(-pos));
    }
    return ret;
}
long long sum_sum(int l,int r)
{
    return query_sum(r)-query_sum(l-1);
}

int where[nmax];

int find_median(int k)
{
    int ok=n,not_ok=0;
    while(ok-not_ok>1)
    {
        int av=(ok+not_ok)/2;
        if(sum_count(1,av)>=(k+1)/2)ok=av;
        else not_ok=av;
    }
    return ok;
}
long long meet_at(long long pos)
{
    long long there_left=sum_count(1,pos-1);
    long long sum_left=sum_sum(1,pos-1);

    long long there_right=sum_count(pos+1,n);
    long long sum_right=sum_sum(pos+1,n);

    long long total_left=pos*there_left-sum_left-1LL*there_left*(there_left+1)/2;

    long long total_right=sum_right-pos*there_right-1LL*there_right*(there_right+1)/2;

    //cout<<"meet_at "<<pos<<" -> "<<there_left<<" "<<sum_left<<" "<<there_right<<" "<<sum_right<<" "<<total_left<<" "<<total_right<<endl;

    return total_left+total_right;
}
int main()
{
    scanf("%i",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%i",&inp[i]);
        where[inp[i]]=i;
    }

    long long inv=0;
    for(int k=1;k<=n;k++)
    {
        inv=inv+sum_count(where[k],n);

        update_count(where[k]);
        update_sum(where[k],where[k]);

        output[k]=inv+meet_at(find_median(k));
    }

    for(int i=1;i<=n;i++)printf("%lld ",output[i]);
    return 0;
}