#include<bits/stdc++.h>
#define l first
#define r second
using namespace std;
using segment = pair<int,int>;
 
void solve()
{
    int n,i,a,b;
    vector<segment> v;
    vector<int> ll;
    vector<int> mm;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a>>b;
        v.push_back({a,b});
        ll.push_back(0);
    }
    ll.push_back(0);
    sort(v.begin(),v.end());
    int cur = 0,maxi = 0;
    for(i=0;i<n;i++)
    {
        int mini = i, maxi = n-1;
        //search for ending
        while(mini < maxi)
        {
            int mid = mini+maxi>>1;
            if(mini == mid)
            {
                if(v[maxi].l > v[i].r)
                    maxi = mini;
                else
                    mini = maxi;
            }
            else
            {
                if(v[mid].l > v[i].r)
                    maxi = mid;
                else
                    mini = mid;
            }
        }
        mm.push_back(maxi-i);
        ll[maxi+1]-=1;
        ll[i]+=1;
        //cout<<i<<' '<<maxi<<' '<<v[i].l<<' '<<v[i].r<<endl;
    }
    for(i=0;i<n;i++)
    {
        cur+=ll[i];
        //cout<<ll[i]<<' ';
        maxi = max(maxi,cur+mm[i]);
    }
    //cout<<endl;
    cout<<n-maxi<<endl;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}