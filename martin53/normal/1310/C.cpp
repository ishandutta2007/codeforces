#include<bits/stdc++.h>
using namespace std;

const int nmax=1e3+42;

string inp;

pair<int,int> order[nmax*nmax];
int pointer;

bool cmp(pair<int,int> a,pair<int,int> b)
{
    for(int i=0;i<=a.second-a.first&&i<=b.second-b.first;i++)
        if(inp[a.first+i]<inp[b.first+i])return 1;
        else if(inp[a.first+i]>inp[b.first+i])return 0;

    if(a.second-a.first!=b.second-b.first)return a.second-a.first<b.second-b.first;
    return a.second<b.second;
}
int n,groups;
long long which;

int mini[nmax],maxi[nmax];

long long dp[nmax][nmax];

pair<long long,long long> pref[nmax][nmax];//k*val.first+val.second;

bool can(int to)
{
    //cout<<"to= "<<to<<endl;

    for(int i=0;i<n;i++)
    {
        mini[i]=1e9;
        maxi[i]=-1;
    }

    for(int i=0;i<=to;i++)
    {
        mini[order[i].first]=min(mini[order[i].first],order[i].second+1);
        maxi[order[i].first]=max(maxi[order[i].first],order[i].second+1);
    }
    /*
    for(int i=0;i<n;i++)
    {
        cout<<i<<" -> "<<mini[i]<<" "<<maxi[i]<<endl;
    }
    */
    memset(dp,0,sizeof(dp));
    memset(pref,0,sizeof(pref));

    for(int pos=n;pos>=0;pos--)
    {
        for(int remain=0;remain<=groups;remain++)
        {
            if(pos==n)
            {
                dp[pos][remain]=(remain==0);
                continue;
            }
            if(remain==0)
            {
                dp[pos][remain]=0;
                continue;
            }
            if(maxi[pos]==-1)continue;

            //cout<<"go "<<pos<<" "<<remain<<endl;

            pair<long long,long long> LHS=pref[mini[pos]][remain-1],RHS=pref[maxi[pos]+1][remain-1];

            pair<long long,long long> diff={LHS.first-RHS.first,LHS.second-RHS.second};

            if(diff.second<0)diff.first--,diff.second+=which;

            if(diff.first)dp[pos][remain]=which;
            else dp[pos][remain]=diff.second;
        }

        for(int remain=0;remain<=groups;remain++)
        {
            //cout<<pos<<" "<<remain<<" -> "<<dp[pos][remain]<<endl;

            pref[pos][remain]=pref[pos+1][remain];

            pref[pos][remain].second+=dp[pos][remain];

            if(pref[pos][remain].second>=which)
            {
                pref[pos][remain].first++;
                pref[pos][remain].second-=which;
            }
        }
    }
    //cout<<to<<" -> "<<rec(0,groups)<<endl;

    //cout<<"found "<<dp[0][which]<<endl;

    return dp[0][groups]>=which;
}

int main()
{
    cin>>n>>groups>>which;

    cin>>inp;

    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            order[pointer]={i,j};
            pointer++;
        }
    }

    sort(order,order+pointer,cmp);
    reverse(order,order+pointer);

    /*
    for(int i=0;i<pointer;i++)
    {
        cout<<i<<" -> "<<order[i].first<<" "<<order[i].second<<" ";for(int t=order[i].first;t<=order[i].second;t++)cout<<inp[t];cout<<endl;
    }
    */

    int not_ok=-1,ok=pointer;

    while(ok-not_ok>1)
    {
        int av=(ok+not_ok)/2;

        if(can(av))ok=av;
        else not_ok=av;
    }

    for(int i=order[ok].first;i<=order[ok].second;i++)
        cout<<inp[i];

    cout<<endl;

    return 0;
}