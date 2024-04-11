/**Ithea is a nice girl.**/
#include<bits/stdc++.h>
using namespace std;
int T;

bool check(int l, int r, int a[],int n)
{
    int i, maxi;
    if(l==-1)
        maxi = a[r];
    else if(r==n)
        maxi = a[l];
    else
        maxi = max(a[l],a[r]);
    int in_maxi = -1e9;
    for(i=l+1; i<r; i++)
        in_maxi = max(in_maxi,a[i]);
    return (maxi > in_maxi);
}

int main()
{
    /**ios_base::sync_with_stdio(false);
    cin.tie(NULL);**/
    int n,m,i,j;
    cin>>n>>m;
    int a[n], b[m], place[m+2];
    int x,k,y;
    long long ans = 0;
    cin>>x>>k>>y;
    bool used = (1LL*y*k >= 1LL*x);
    bool pass = true;
    map<int,int> mp;
    for(i=0; i<n; i++)
    {
        cin>>a[i];
        mp.insert({a[i],i});
    }
    for(i=0; i<=m; i++)
        b[i] = 0;
    place[0] = -1, place[m+1] = n;
    for(i=0; i<m; i++)
    {
        cin>>b[i];
        if(mp.count(b[i]))
        {
            place[i+1] = mp[b[i]];
        }
        else
            pass = false;
    }
    if(pass)
    {
        for(i=0; i<m+1; i++)
        {
            if(place[i]>place[i+1])
                pass = false;
        }
    }
    if(!pass)
        cout<<"-1\n";
    else
    {
        for(i=0; i<m+1; i++)
        {
            if(ans==-1)
                break;
            int siz = place[i+1]-place[i]-1;
            if(siz > 0)
            {
                if(used)
                {
                    if(siz<k)
                    {
                        bool in = check(place[i],place[i+1],a,n);
                        if(in)
                            ans+=1LL*siz*y;
                        else
                            ans = -1;
                    }
                    else
                    {
                        ans+=1LL*(siz/k)*x+1LL*(siz%k)*y;
                    }
                }
                else
                {
                    bool in = check(place[i],place[i+1],a,n);
                    if(!in)
                    {
                        if(siz < k)
                            ans = -1;
                        else
                            ans+=1LL*x+1LL*(siz-k)*y;
                    }
                    else
                    {
                        ans+=1LL*siz*y;
                    }
                }
            }
        }
        cout<<ans;
    }
    return 0;
}

/**
3
1 1
69 420
148 320
**/