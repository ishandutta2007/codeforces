#include<bits/stdc++.h>
using namespace std;

const int nmax=2e5+42;

int sz,n;

pair<int/*position*/,int/*id*/> inp[nmax],target[nmax];

map<int,int> diff;

map<int,int> mem;

int find_mid()
{
    vector< pair<int,int> > noted={};

    for(auto k:diff)
        if(k.second)
        {
            noted.push_back(k);
        }

    noted.push_back({sz,0});

    int prv=0,sum=0;

    //count prefix sum of [0, 0], [0, 1], ... [0, m-1]

    for(auto k:noted)
    {
        //k.first-prv times sum
        mem[sum]+=k.first-prv;

        prv=k.first;

        sum+=k.second;
    }

    sum=0;

    vector< pair<int,int> > active={};

    for(auto k:mem)
    {
        sum+=k.second;
    }

    sum=(sum+1)/2;

    for(auto k:mem)
    {
        sum=sum-k.second;
        if(sum<=0)
        {
            //the cutoff is k.first
            long long score=0;

            for(auto p:mem)
            {
                score+=1LL*abs(-k.first+p.first)*p.second;
            }

            printf("%lld\n",score);

            return -k.first;
        }
    }

    assert(0==1);
}

int outp[nmax];
int main()
{
    scanf("%i%i",&sz,&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%i",&inp[i].first);
        inp[i].second=i;

        diff[inp[i].first]++;
    }

    sort(inp+1,inp+n+1);

    for(int i=1;i<=n;i++)
    {
        scanf("%i",&target[i].first);
        target[i].second=i;

        diff[target[i].first]--;
    }

    sort(target+1,target+n+1);

    int moved=find_mid();

    //cout<<moved<<endl;

    //moved people moved m -> 1
    //if moved<0, -moved moved 1 -> m

    for(int i=1;i<=n;i++)
    {
        int j=((i+moved)%n+n)%n;

        if(j==0)j=n;

        outp[inp[i].second]=target[j].second;
    }

    for(int i=1;i<=n;i++)
        printf("%i ",outp[i]);
    printf("\n");

    return 0;
}