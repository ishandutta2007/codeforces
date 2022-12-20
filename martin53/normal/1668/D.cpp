#include<bits/stdc++.h>
using namespace std;

const int nmax=5e5+42;

int n,inp[nmax];

long long pref[nmax];

set< pair<long long/*pref*/,int/*value*/> > active;

void push(long long pref,int value)
{
    set< pair<long long/*pref*/,int/*value*/> >::iterator it=active.lower_bound({pref+1,-2*n});

    if(it!=active.begin())
    {
        it--;

        if((*it).second>=value)return;
    }

    while(active.size())
    {
        set< pair<long long/*pref*/,int/*value*/> >::iterator it=active.lower_bound({pref,-1});

        if(it==active.end())break;

        pair<long long/*pref*/,int/*value*/> cur=(*it);

        if(cur.second<=value)
        {
            active.erase(it);
            continue;
        }
        else break;
    }

    active.insert({pref,value});
}

int dp[nmax];

map<long long,int> case_2;

mt19937 rng(42);

int solve()
{
    scanf("%i",&n);

    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);


    /*
    n=5;
    for(int i=1;i<=n;i++)inp[i]=2-rng()%5;

    cout<<n<<endl;
    for(int i=1;i<=n;i++)cout<<inp[i]<<" ";cout<<endl;
    */

    for(int j=1;j<=n;j++)
        pref[j]=pref[j-1]+inp[j];

    active={};

    active.insert({0,0});
    dp[0]=0;

    case_2={};
    case_2[0]=0;

    int case_3=0;

    for(int i=1;i<=n;i++)
    {
        //cout<<"i= "<<i<<" active= ";for(auto w:active)cout<<w.first<<" "<<w.second<<"\t";cout<<endl;

        dp[i]=case_3-i;

        set< pair<long long/*pref*/,int/*value*/> >::iterator it=active.lower_bound(make_pair(pref[i],-3*n-1));

        if(it!=active.begin())
        {
            it--;

            dp[i]=max(dp[i],i+(*it).second);

            //cout<<"case 1 -> "<<i<<" "<<dp[i]<<endl;
        }

        if(case_2.count(pref[i]))dp[i]=max(dp[i],case_2[pref[i]]);



        push(pref[i],dp[i]-i);



        if(case_2.count(pref[i]))case_2[pref[i]]=max(case_2[pref[i]],dp[i]);
        else case_2[pref[i]]=dp[i];

        case_3=max(case_3,dp[i]+i);

        //cout<<i<<" -> "<<dp[i]<<endl;

        /*
        int MX=-n;

        for(int j=0;j<i;j++)
            if(pref[j]<pref[i])MX=max(MX,dp[j]+i-j);
            else if(pref[j]==pref[i])MX=max(MX,dp[j]);
            else MX=max(MX,dp[j]+j-i);

        //cout<<i<<" -> "<<dp[i]<<" "<<MX<<endl;

        assert(dp[i]==MX);
        */
    }

    return dp[n];
}

int main()
{
    int t;

    //t=1e5;

    scanf("%i",&t);

    while(t)
    {
        t--;

        //solve();
        printf("%i\n",solve());
    }

    return 0;
}