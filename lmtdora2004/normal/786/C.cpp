#include <bits/stdc++.h>
#define int long long
 
using namespace std;
 
int n;
int a[100005];
int cnt[100005];
int bit[100005];
int minans=0;
int ansed[100005];
 
void update(int pos, int val)
{
    while(pos<=n)
    {
        bit[pos]=min(bit[pos], val);
        pos+=pos&-pos;
    }
}
 
int get(int pos)
{
    int ans=n;
    while(pos>0)
    {
        ans=min(ans, bit[pos]);
        pos-=pos&-pos;
    }
    return ans;
}
 
int solve(int k)
{
    if(ansed[k]) return ansed[k];
    memset(cnt, 0, sizeof(cnt));
    int tot=0, ans=1;
    int last=1;
    for(int i=1; i<=n; i++)
    {
        cnt[a[i]]++;
        if(cnt[a[i]]==1)
        {
            tot++;
            if(tot>k)
            {
                ans++;
                for(int j=last; j<i; j++)
                {
                    cnt[a[j]]--;
                    if(cnt[a[j]]==0)
                    {
                        tot--;
                    }
                }
                last=i;
            }
        }
    }
    ansed[k]=ans;
    return ans;
}
 
signed main()
{
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
    }
    for(int i=1; i<=n; i++)
    {
        bit[i]=n;
    }
    // cout<<solve(2)<<endl;
    int sq=1;//sqrt(n);
    minans=n;
    for(int k=1; k<=sq; k++)
    {
        // cout<<k<<" "<<solve(k)<<" "<<minans<<endl;
        int ans=solve(k);
        if(k!=sq) cout<<ans<<" ";
        minans=min(minans, ans);
    }
    // cout<<minans<<endl;
    // cout<<endl;
    int lo=sq, hi=n;
    while(lo<hi)
    {
        int mid=(lo+hi+1)/2, lol=solve(mid);
        update(lol, mid);
        if(lol!=minans) hi=mid-1;
        else lo=mid;
    }
    // cout<<minans<<endl;
    // cout<<1<<endl;
    int curlast=lo;
    for(int i=sq; i<=n; i++)
    {  
        if(i>curlast)
        {
            // cout<<"CHECK "<<i<<endl;
            int lo=i, hi=get(minans-1);
            // cout<<lo<<" "<<hi<<endl;
            minans=solve(i);
            while(lo<hi)
            {
                int mid=(lo+hi+1)/2, lol=solve(mid);
                update(lol, mid);
                if(lol!=minans) hi=mid-1;
                else lo=mid;
            }
            curlast=lo;
        }
        cout<<minans<<" ";
    }
    cout<<endl;
}