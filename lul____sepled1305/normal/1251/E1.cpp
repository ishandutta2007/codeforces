#include<bits/stdc++.h>
using namespace std;
int T;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>T;
    while(T--)
    {
        int i,n,water=0;
        long long ans = 0LL;
        cin>>n;
        pair<int,int> a[n];
        priority_queue<int> pq;
        for(i=0;i<n;i++)
        {
            int p,m;
            cin>>m>>p;
            a[i] = {m,p};
        }
        sort(a,a+n);
        for(i=n-1;i>=0;i--)
        {
            if(a[i].first-i-water<=0)
                pq.push(-a[i].second);
            else
            {
                int val = 1e9+15;
                if(!pq.empty())
                    val = -pq.top();
                if(val>a[i].second)
                    ans+=a[i].second;
                else
                {
                    ans+=val;
                    pq.pop();
                    pq.push(-a[i].second);
                }
                water++;
            }
        }
        cout<<ans<<"\n";
    }
}