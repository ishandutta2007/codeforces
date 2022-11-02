#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
const int MOD = 1e9+7;
vector<int> dp[1000];
vector<int> quick[1000];
vector<pii> _sort[1000];
string a[1000];
int n,i,j,k;
 
bool compare(int pl1, int pl2, int s1, int s2)
{
    int i;
    bool pass = true;
    bool undecide = true;
    bool siz_dif = true;
    int pointer1 = 0, pointer2 = 0;
    while(pointer1 < a[s1].size() && pointer2 < a[s2].size())
    {
        if(pointer1 == pl1)
            pointer1++;
        if(pointer2 == pl2)
            pointer2++;
 
        if(pointer1 >= a[s1].size() || pointer2 >= a[s2].size())
            break;
        if(a[s1].at(pointer1) < a[s2].at(pointer2))
        {
            pass = true;
            undecide = false;
            break;
        }
        else if (a[s1].at(pointer1) > a[s2].at(pointer2))
        {
            pass = false;
            undecide = false;
            break;
        }
 
        pointer1++;
        pointer2++;
    }
    if(pointer1 == pl1)
        pointer1++;
    if(pointer2 == pl2)
        pointer2++;
    if(pointer1 < a[s1].size())
        siz_dif = false;
    else
        siz_dif = true;
    if(undecide)
        return siz_dif;
    else
        return pass;
}
 
bool comp (pii &x, pii &y)
{
    int sq = x.first;
    int fi = x.second;
    int se = y.second;
    if(fi > se)
    {
        if(quick[sq][fi] == quick[sq][se])
            return false;
        else
        {
            return (a[sq].at(quick[sq][se]) > a[sq].at(se));
        }
    }
    else
    {
        if(quick[sq][fi] == quick[sq][se])
            return true;
        else
        {
            return (a[sq].at(quick[sq][fi]) < a[sq].at(fi));
        }
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    if(n<200)
    {
        for(i=0;i<n;i++)
            cin>>a[i];
        for(i=n-1;i>=0;i--)
        {
            int pointer1 = 0, pointer2 = 0;
            while(pointer2 < a[i].size())
            {
                while(pointer2 < a[i].size() && a[i].at(pointer1) == a[i].at(pointer2))
                    pointer2++;
 
                if(pointer2 == a[i].size())
                    break;
                while(pointer1 < pointer2)
                {
                    quick[i].push_back(pointer2);
                    pointer1++;
                }
            }
            while(pointer1 <= a[i].size())
                quick[i].push_back(a[i].size()),pointer1++;
            dp[i].push_back(0);
            for(j=0;j<a[i].size();j++)
                dp[i].push_back(0);
            _sort[i].push_back({i,a[i].size()});
            for(j=0;j<a[i].size();j++)
                _sort[i].push_back({i,j});
            sort(_sort[i].begin(),_sort[i].end(),comp);
            reverse(_sort[i].begin(),_sort[i].end());
            if(i == n-1)
            {
                for(j=0;j<dp[i].size();j++)
                    dp[i][j] = 1;
            }
            else
            {
                long long sum = 0;
                int pointer = 0;
                for(j=0;j<dp[i].size();j++)
                {
                    while(pointer < dp[i+1].size() && compare(_sort[i][j].second,_sort[i+1][pointer].second,i,i+1))
                    {
                        sum+=dp[i+1][_sort[i+1][pointer].second];
                        sum%=MOD;
                        pointer++;
                    }
                    dp[i][_sort[i][j].second]+=sum;
                }
            }
        }
        int ans = 0;
        for(i=0;i<dp[0].size();i++)
        {
            ans+=dp[0][i];
            ans%=MOD;
        }
        cout<<ans<<endl;
    }
    else
    {
        for(i=0;i<n;i++)
            cin>>a[i];
        for(i=n-1;i>=0;i--)
        {
            dp[i].push_back(0);
            for(j=0;j<a[i].size();j++)
                dp[i].push_back(0);
            if(i == n-1)
            {
                for(j=0;j<dp[i].size();j++)
                    dp[i][j] = 1;
            }
            else
            {
                for(j=0;j<dp[i].size();j++)
                {
                    for(k=0;k<dp[i+1].size();k++)
                    {
                        if(compare(j,k,i,i+1))
                        {
                            dp[i][j]+=dp[i+1][k];
                            dp[i][j]%=MOD;
                        }
                    }
                }
            }
        }
        int ans = 0;
        for(i=0;i<dp[0].size();i++)
        {
            ans+=dp[0][i];
            ans%=MOD;
        }
        /**for(i=0;i<n;i++)
        {
            for(j=0;j<dp[i].size();j++)
            {
                cout<<i<<' '<<j<<' '<<dp[i][j]<<endl;
            }
        }**/
        cout<<ans<<endl;
    }
    return 0;
}