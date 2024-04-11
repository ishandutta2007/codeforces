#include<bits/stdc++.h>
using namespace std;

const int nmax=4e6+42;

int dp[nmax];
int n,m;

int dvd[nmax];

long long sum_pref=1,sum_dvd=0;

pair<int,int> primes[nmax];

int pointer=0;

int NUM_NOW;

void dfs(int pos,int val)
{
    if(pos==pointer+1)
    {
        if(val==1)return;

        sum_dvd=(sum_dvd-dp[(NUM_NOW-1)/val]+dp[NUM_NOW/val]+m)%m;

        //cout<<NUM_NOW<<" with "<<val<<" -> "<<sum_dvd<<endl;

        return;
    }

    for(int i=0;i<=primes[pos].second;i++)
    {
        dfs(pos+1,val);
        val=val*primes[pos].first;
    }
}

void eval(int val)
{
    NUM_NOW=val;

    pointer=0;

    while(val>1)
    {
        pointer++;

        primes[pointer].first=dvd[val];
        primes[pointer].second=0;

        while(val%primes[pointer].first==0)
        {
            //cout<<"gaz "<<val<<" "<<primes[pointer].first<<endl;

            val=val/primes[pointer].first;

            primes[pointer].second++;
        }
    }

    //for(int i=1;i<=pointer;i++)cout<<primes[i].first<<" with "<<primes[i].second<<endl;

    dfs(1,1);
}

int main()
{
    scanf("%i%i",&n,&m);

    for(int i=2;i<=n;i++)
        if(dvd[i]==0)
        {
            dvd[i]=i;

            for(long long j=1LL*i*i;j<=n;j=j+i)
                if(dvd[j]==0)dvd[j]=i;
        }

    dp[1]=1;

    for(int i=2;i<=n;i++)
    {
        //cout<<"i= "<<i<<endl;

        dp[i]=sum_pref;

        eval(i);

        dp[i]=(dp[i]+sum_dvd)%m;

        sum_pref=(sum_pref+dp[i])%m;

        //cout<<i<<" -> "<<dp[i]<<" "<<sum_pref<<" "<<sum_dvd<<endl;
    }

    printf("%i\n",dp[n]);

    return 0;
}