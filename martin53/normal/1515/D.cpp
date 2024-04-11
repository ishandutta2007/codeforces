#include<bits/stdc++.h>
using namespace std;

const int nmax=2e5+42;

int n,l,r;

map<int,int> seen;

int solve()
{
    scanf("%i%i%i",&n,&l,&r);

    seen={};

    for(int i=1;i<=l;i++)
    {
        int cur;
        scanf("%i",&cur);

        seen[cur]++;
    }

    for(int i=l+1;i<=n;i++)
    {
        int cur;
        scanf("%i",&cur);

        seen[cur]--;
    }

    int outp=0;

    int cnt[2]={0,0};
    int one_move[2]={0,0};

    for(auto w:seen)
    {
        int now=w.second;

        if(now>0)cnt[0]+=now,one_move[0]+=now/2;
        else if(now<0)cnt[1]-=now,one_move[1]-=now/2;
    }

    if(cnt[0]>cnt[1])swap(cnt[0],cnt[1]),swap(one_move[0],one_move[1]);

    //cnt[0]<=cnt[1]

    //cout<<outp<<" "<<cnt[0]<<" "<<cnt[1]<<endl;

    outp+=cnt[0];

    cnt[1]=cnt[1]-cnt[0];

    //cout<<cnt[1]<<" "<<one_move[1]<<" -> "<<outp<<endl;

    if(2*one_move[1]>=cnt[1])outp+=cnt[1]/2;
    else outp+=one_move[1]+(cnt[1]-2*one_move[1]);

    return outp;
}

int main()
{
    int t;
    scanf("%i",&t);

    while(t)
    {
        t--;

        printf("%i\n",solve());
    }


    return 0;
}