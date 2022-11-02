#include<bits/stdc++.h>
using namespace std;
vector<pair<long long,long long>> v;
vector<pair<long long,long long>> cal;
long long i,j,k,quicksum,n,m,repeat,ans,save1=0;
long long dp;
int main()
{
    scanf("%lld",&n);
    pair<long long, long long> l;
    l.first=0;
    l.second=0;
    v.push_back(l);
    for(i=1;i<=n;i++)
    {
        scanf("%lld",&m);
        quicksum+=m;
        pair<long long, long long> l;
        l.first = quicksum;
        l.second = i;
        v.push_back(l);
    }
    sort(v.begin(),v.end());
    for(i=1;i<=n;i++)
    {
        if(v[i].first==v[i-1].first)
        {
            l.first=v[i].second;
            l.second=v[i-1].second+1;
            cal.push_back(l);
        }
    }
    sort(cal.begin(),cal.end());
    long long ss=cal.size()-1;
    if(!cal.empty()){
    for(i=1;i<=n;i++)
    {
        bool f=true;
        if(k<=ss)
            if(i!=cal[k].first)
            {
                dp+=i-save1;
                f=false;
            }
            else f=true;
        if(f)
        {
            while(k<=ss-1)
            {
                if(i==cal[k+1].first)
                    k++;
                else
                    break;
            }
            if(k==ss-1)
            {
                if(i==cal[k+1].first)
                {
                    k++;
                    save1 = max(cal[k].second,save1);
                }
                else if (i==cal[k].first)
                    save1 = max(cal[k].second,save1);
            }
            else if(k<=ss)
            {
                if(i==cal[k].first)
                    save1 = max(cal[k].second,save1);
            }
            dp+=i-save1;
            k++;
        }
    }
    }
    else
    {
        dp = ((n)*(n+1))/2;
    }
    cout<<dp;
    return 0;
}