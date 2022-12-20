#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;

int n,changes,SZ;

int help[nmax],pointer=0;

pair<long long/*cost*/,long long/*groups*/> dp[nmax];

deque< int > active,idle;

void eval(long long cost)
{
    //cout<<"cost= "<<cost<<endl;

    active=idle;

    dp[0]={0,0};

    for(int i=1;i<=pointer;i++)
    {
        dp[i]={dp[i-1].first+1,dp[i-1].second};

        while(active.size()&&help[i]-help[active.front()]+1>SZ)active.pop_front();

        while(active.size()&&dp[active.back()-1]>=dp[i-1])active.pop_back();

        active.push_back(i);

        //cout<<i<<" with "<<active.front()<<" "<<active.size()<<" "<<active.back()<<endl;

            pair<long long,long long> cur=dp[active.front()-1];

            cur.first+=cost;
            cur.second++;

            dp[i]=min(dp[i],cur);


        /*
        cout<<i<<" -> "<<dp[i].first<<" "<<dp[i].second<<endl;

        for(int j=i;j>=1&&help[i]-help[j]+1<=SZ;j--)
        {
            pair<long long,long long> cur=dp[j-1];

            cur.first+=cost;
            cur.second++;

            if(dp[i]>cur)
            {
                cout<<"wrong "<<i<<" "<<j<<" "<<dp[i].first<<" "<<dp[i].second<<" with "<<cur.first<<" "<<cur.second<<endl;
                system("pause");
            }
        }
        */
    }

    /*
    cout<<"cost= "<<cost<<endl;
    for(int i=1;i<=pointer;i++)cout<<dp[i].first<<" "<<dp[i].second<<endl;
    cout<<"---"<<endl;
    */
}
int solve(vector<int> inp)
{
    if(inp.size()<=changes)return 0;
    //cout<<"inp: ";for(auto k:inp)cout<<k<<" ";cout<<endl;

    pointer=0;
    for(auto k:inp)
    {
        pointer++;
        help[pointer]=k;
    }

    long long ok=-1e9,not_ok=1e9;//f(ok).second=inp.size()

    eval(ok);
    eval(not_ok);

    while(not_ok-ok>1)
    {
        long long av=(ok+not_ok)/2;

        eval(av);

        if(dp[pointer].second>=changes)ok=av;
        else not_ok=av;
    }

    //cout<<"ok= "<<ok<<" not_ok= "<<not_ok<<endl;

    eval(not_ok);

    return dp[pointer].first-1LL*changes*not_ok;
    //return dp[pointer].first-1LL*dp[pointer].second*not_ok-1LL*ok*(changes-dp[pointer].second);
}
int main()
{
    cin>>n>>changes>>SZ;

    string inp;
    cin>>inp;

    vector<int> groups[2]={{},{}};

    for(int i=0;i<n;i++)
        if('a'<=inp[i]&&inp[i]<='z')groups[0].push_back(i);
        else groups[1].push_back(i);

    cout<<min(solve(groups[0]),solve(groups[1]))<<endl;
    return 0;
}