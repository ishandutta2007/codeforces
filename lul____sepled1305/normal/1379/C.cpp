#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
int T;

int main()
{
    cin>>T;
    while(T--)
    {
        int n,i,maxi = 0,m,index= 0;
        long long ans = 0;
        cin>>n>>m;
        pii flower[m];
        vector<pii> best;
        vector<int> idx;
        for(i=0;i<m;i++)
        {
            int a,b;
            cin>>a>>b;
            flower[i] = {a,b};
            if(maxi<b)
            {
                maxi =b;
                index = i;
            }
        }
        sort(flower,flower+m,greater<pii> ());
        long long quick[m];
        long long cur = 0;
        for(i=0;i<m;i++)
        {
            cur+=flower[i].first;
            quick[i] = cur;
        }
        for(i=0;i<m;i++)
        {
            long long tar = flower[i].second;
            long long val = 0;
            int mini = 0, maxi = m-1;
            while(mini<maxi)
            {
                if(flower[mini].first < flower[i].second)
                {
                    mini = -1;
                    break;
                }
                int mid = mini+maxi>>1;
                if(mini == mid)
                {
                    if(flower[maxi].first >= tar)
                        mini = maxi;
                    else
                        maxi = mini;
                }
                else
                {
                    if(flower[mid].first > flower[i].second)
                        mini = mid;
                    else
                        maxi = mid;
                }
            }
            long long sum = min(mini,n-1);
            if(sum==-1)
                val = 0;
            else
                val = quick[sum];
            if(sum!=n-1)
            {
                if(mini<i)
                {
                    val+=flower[i].first;
                    sum++;
                }
                val+=1LL*(n-sum-1)*flower[i].second;
            }
            ans = max(val,ans);
        }
        cout<<ans<<"\n";
    }
}
/**
    I really hate this round.
**/