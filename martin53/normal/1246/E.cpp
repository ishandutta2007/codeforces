#include<bits/stdc++.h>
using namespace std;

const int nmax=16,MX=16*2000+42;

int n,k,inp[nmax];

int outp[nmax];

void print()
{
    vector< pair<int,int> > active;

    cout<<"YES"<<endl;

    for(int i=0;i<n;i++)
        active.push_back({inp[i],outp[i]});

    for(int t=1;t<n;t++)
    {
        for(int i=0;i<active.size();i++)
            for(int j=i+1;j<active.size();j++)
                if(active[i].second==active[j].second)
                {
                    cout<<active[i].first<<" "<<active[j].first<<endl;

                    active[i].first+=active[j].first;

                    while(active[i].first%k==0)
                    {
                        active[i].first=active[i].first/k;
                        active[i].second--;
                    }

                    active.erase(active.begin()+j,active.begin()+j+1);
                    i=n;
                    j=n;
                }
    }

    exit(0);
}

bitset<MX> on[1<<nmax];

int sum[1<<nmax];

void go(int aim,int deg,int mask)
{
    if(aim==0&&mask==0)print();

    if(aim>sum[mask]||aim<0)return;

    if(on[mask][aim])return;

    on[mask][aim]=1;

    //do nothing
    go(aim*k,deg+1,mask);

    //subtract
    for(int i=0;i<n;i++)
        if((mask&(1<<i)))
        {
            outp[i]=deg;

            go(aim-inp[i],deg,mask-(1<<i));
        }
}
int main()
{
    cin>>n>>k;
    for(int i=0;i<n;i++)cin>>inp[i];

    for(int mask=0;mask<(1<<n);mask++)
        for(int i=0;i<n;i++)
            if((mask&(1<<i)))sum[mask]+=inp[i];

    go(1,0,(1<<n)-1);

    cout<<"NO"<<endl;

    return 0;
}