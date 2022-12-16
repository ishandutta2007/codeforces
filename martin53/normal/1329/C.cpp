#include<bits/stdc++.h>
using namespace std;
const int nmax=(1<<21)+42;
int n,h,g;
pair<int,int> inp[nmax];
int outp[nmax];

int where_is[nmax];

int state[nmax];

int would_end(int i)
{
    int le=2*i,ri=2*i+1;

    if(state[le]==0&&state[ri]==0)return i;

    if(state[le]>state[ri])return would_end(le);
    return would_end(ri);
}

void place(int i)
{
    int le=2*i,ri=2*i+1;

    if(state[le]==0&&state[ri]==0)
    {
        where_is[state[i]]=0;
        state[i]=0;
        return;
    }

    if(state[le]>state[ri])
    {
        where_is[state[le]]=i;
        swap(state[le],state[i]);

        place(le);
        return;
    }

    where_is[state[ri]]=i;
    swap(state[ri],state[i]);

    place(ri);
    return;
}
void solve()
{
    scanf("%i%i",&h,&g);

    int n=(1<<h)-1;

    long long sum=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%i",&inp[i].first);

        sum=sum+inp[i].first;

        state[i]=inp[i].first;

        inp[i].second=i;
        where_is[inp[i].first]=i;
    }

    sort(inp+1,inp+n+1);

    int pointer=0;
    for(int i=n;i>=1;i--)
    {
        int pos=where_is[inp[i].first];

        //cout<<"pos= "<<pos<<" would_end= "<<would_end(pos)<<endl;
        //for(int j=1;j<=n;j++)cout<<state[j]<<" ";cout<<endl;

        if(would_end(pos)>=(1<<g))
        {
            pointer++;
            outp[pointer]=pos;

            place(pos);

            sum=sum-inp[i].first;
        }
    }

    printf("%lld\n",sum);

    for(int i=1;i<=pointer;i++)printf("%i ",outp[i]);
    printf("\n");

    for(int i=1;i<=n;i++)
        where_is[inp[i].first]=0,state[i]=0;
}
int main()
{
    int t;
    scanf("%i",&t);

    for(int i=1;i<=t;i++)
        solve();

    return 0;
}