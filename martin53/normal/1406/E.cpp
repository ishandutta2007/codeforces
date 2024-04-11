#include<bits/stdc++.h>
using namespace std;

int ask(char type,int x)
{
    cout<<type<<" "<<x<<endl;
    cout.flush();

    int ret;
    cin>>ret;
    return ret;
}

void answer(int cur)
{
    cout<<'C'<<" "<<cur<<endl;
    cout.flush();

    exit(0);
}

const int nmax=1e5+42;

bitset<nmax> prime;/*1-> not prime*/

bool active[nmax];

int n;

int main()
{
    for(int i=2;i*i<nmax;i++)
        if(prime[i]==0)
        {
            for(int j=i*i;j<nmax;j=j+i)
                prime[j]=1;
        }

    cin>>n;

    for(int i=1;i<=n;i++)
        active[i]=1;

    if(n==1)answer(1);

    vector<int> primes={};
    for(int p=2;p<=n;p++)
        if(prime[p]==0)
            primes.push_back(p);

    int ret=1,groups=sqrt(primes.size()+0.1);

    int cnt=0;

    bool found_extra=0;

    vector<int> last={};

    for(auto p:primes)
    {
        int cur=ask('B',p);

        int should=0;

        for(int j=p;j<=n;j=j+p)
            if(active[j]==1)
            {
                should++;
                active[j]=0;
            }

        if(cur>should)
        {
            ret=ret*p;
        }

        last.push_back(p);

        cnt++;

        if(found_extra==0&&cnt==groups)
        {
            int cur=ask('A',1);
            int should=0;
            for(int i=1;i<=n;i++)
                should+=active[i];

            if(cur!=should)
            {
                for(auto q:last)
                    if(ask('B',q))
                    {
                        ret=ret*q;

                        found_extra=1;

                        break;
                    }
            }

            cnt=0;
            last={};
        }
    }

        if(found_extra==0)
        {
            int cur=ask('A',1);
            int should=0;
            for(int i=1;i<=n;i++)
                should+=active[i];

            if(cur!=should)
            {
                for(auto q:last)
                    if(ask('B',q))
                    {
                        ret=ret*q;

                        found_extra=1;

                        break;
                    }
            }

            cnt=0;
            last={};
        }

    for(auto p:primes)
        while(ret%p==0&&ret<=n/p)
        {
            int ret_new=ret*p;

            if(ask('A',ret_new))ret=ret_new;
            else break;
        }

    answer(ret);

    return 0;
}