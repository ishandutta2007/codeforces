#include<bits/stdc++.h>
using namespace std;

const int nmax=1e5+42,mod=998244353;

int k,a,h;

long long pwr[nmax];

long long arr[nmax];

pair<int,int> active[nmax];
int pointer=0;

int cur[nmax];

map<int, vector<int> > seen[2];

void print(vector<int> a)
{
    for(auto w:a)
        printf("%i ",w);
}

int main()
{
    scanf("%i%i%i",&k,&a,&h);

    pwr[0]=1;
    for(int i=1;i<=(1<<k);i++)pwr[i]=1LL*pwr[i-1]*a%mod;

    int games=(1<<k)/2-1;

    for(int mask=0;mask<(1<<games);mask++)
    {
        pointer=0;

        for(int i=1;i<=(1<<k)/2;i++)
        {
            pointer++;
            active[pointer]={i,(1<<k)/2+1};
        }

        int bit=0;

        for(int j=1;j<pointer;j+=2)
        {
            if((mask&(1<<bit)))
            {
                cur[active[j].first]=active[j].second;
                pointer++;
                active[pointer]={active[j+1].first,(active[j+1].second+1)/2};
            }
            else
            {
                cur[active[j+1].first]=active[j+1].second;
                pointer++;
                active[pointer]={active[j].first,(active[j].second+1)/2};
            }
            bit++;
        }

        //as 2
        cur[active[pointer].first]=2;
        vector<int> order={};
        long long sum=0;
        for(int i=1;i<=(1<<k)/2;i++)
        {
            order.push_back(cur[i]);
            sum=(sum+1LL*i*pwr[cur[i]])%mod;
        }
        seen[0][sum]=order;
        //cout<<0<<" "<<sum<<" -> ";for(auto w:order)cout<<w<<" ";cout<<endl;

        //as 1
        cur[active[pointer].first]=1;
        order={};
        sum=0;
        for(int i=1;i<=(1<<k)/2;i++)
        {
            order.push_back(cur[i]);
            sum=(sum+1LL*i*pwr[cur[i]])%mod;
        }
        seen[1][sum]=order;
        //cout<<1<<" "<<sum<<" -> ";for(auto w:order)cout<<w<<" ";cout<<endl;
    }

    //cout<<"other: "<<endl;


    for(int mask=0;mask<(1<<games);mask++)
    {
        pointer=0;

        for(int i=(1<<k)/2+1;i<=(1<<k);i++)
        {
            pointer++;
            active[pointer]={i,(1<<k)/2+1};
        }

        int bit=0;

        for(int j=1;j<pointer;j+=2)
        {
            if((mask&(1<<bit)))
            {
                cur[active[j].first]=active[j].second;
                pointer++;
                active[pointer]={active[j+1].first,(active[j+1].second+1)/2};
            }
            else
            {
                cur[active[j+1].first]=active[j+1].second;
                pointer++;
                active[pointer]={active[j].first,(active[j].second+1)/2};
            }
            bit++;
        }

        //as 2
        cur[active[pointer].first]=2;
        vector<int> order={};
        long long sum=0;
        for(int i=(1<<k)/2+1;i<=(1<<k);i++)
        {
            order.push_back(cur[i]);
            sum=(sum+1LL*i*pwr[cur[i]])%mod;
        }

        //cout<<0<<" "<<sum<<" -> ";for(auto w:order)cout<<w<<" ";cout<<endl;

        long long other=(h-sum+mod)%mod;

        if(seen[1].count(other))
        {
            print(seen[1][other]);
            print(order);
            return 0;
        }

        //as 1
        cur[active[pointer].first]=1;
        order={};
        sum=0;
        for(int i=(1<<k)/2+1;i<=(1<<k);i++)
        {
            order.push_back(cur[i]);
            sum=(sum+1LL*i*pwr[cur[i]])%mod;
        }

        //cout<<1<<" "<<sum<<" -> ";for(auto w:order)cout<<w<<" ";cout<<endl;

        other=(h-sum+mod)%mod;

        if(seen[0].count(other))
        {
            print(seen[0][other]);
            print(order);
            return 0;
        }
    }
    printf("-1\n");

    return 0;
}
//h=sum(i*A^pi)