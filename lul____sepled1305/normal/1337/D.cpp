#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
ll i,j,k,n,t,mini=1e18;
 
ll problem(ll aa, ll bb, ll cc)
{
    return 2*(aa*aa+bb*bb+cc*cc-aa*bb-bb*cc-cc*aa);
}
 
ll bsearch(ll mini, ll maxi, ll target, vector<ll> &v )
{
    while(maxi > mini)
    {
        //cout<<mini<<maxi<<"\n";
        ll mid = maxi+mini >>1;
        if(mid == mini) mid++;
        if(v[mid] <= target)
            mini=mid;
        else
            maxi=mid-1;
    }
    return mini;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cin>>t;
    while(t)
    {
        ll a[5];
        vector<ll> prob[5];
        t--;
        mini=2e18;
        cin>>a[0]>>a[1]>>a[2];
        for(i=0;i<3;i++)
        {
            for(j=0;j<a[i];j++)
            {
                cin>>k;
                prob[i].push_back(k);
            }
        }
        sort(prob[0].begin(),prob[0].end());
        sort(prob[1].begin(),prob[1].end());
        sort(prob[2].begin(),prob[2].end());
        for(j=0;j<a[0];j++)
        {
            ll checking1, checking2;
            ll checking3, checking4;
            checking1 = bsearch(0,a[1]-1,prob[0][j],prob[1]);
            checking2 = bsearch(0,a[2]-1,prob[0][j],prob[2]);
            if(checking1 == a[1]-1) checking3 = a[1]-1;
            else checking3 = checking1+1;
            if(checking2 == a[2]-1) checking4 = a[2]-1;
            else checking4 = checking2+1;
            mini = min(mini , problem(prob[0][j],prob[1][checking1],prob[2][checking2]));
            mini = min(mini , problem(prob[0][j],prob[1][checking1],prob[2][checking4]));
            mini = min(mini , problem(prob[0][j],prob[1][checking3],prob[2][checking2]));
            mini = min(mini , problem(prob[0][j],prob[1][checking3],prob[2][checking4]));
        }
        for(j=0;j<a[1];j++)
        {
            ll checking1, checking2;
            ll checking3, checking4;
            checking1 = bsearch(0,a[0]-1,prob[1][j],prob[0]);
            checking2 = bsearch(0,a[2]-1,prob[1][j],prob[2]);
            if(checking1 == a[0]-1) checking3 = a[0]-1;
            else checking3 = checking1+1;
            if(checking2 == a[2]-1) checking4 = a[2]-1;
            else checking4 = checking2+1;
            mini = min(mini , problem(prob[1][j],prob[0][checking1],prob[2][checking2]));
            mini = min(mini , problem(prob[1][j],prob[0][checking1],prob[2][checking4]));
            mini = min(mini , problem(prob[1][j],prob[0][checking3],prob[2][checking2]));
            mini = min(mini , problem(prob[1][j],prob[0][checking3],prob[2][checking4]));
        }
        for(j=0;j<a[2];j++)
        {
            ll checking1, checking2;
            ll checking3, checking4;
            checking1 = bsearch(0,a[1]-1,prob[2][j],prob[1]);
            checking2 = bsearch(0,a[0]-1,prob[2][j],prob[0]);
            if(checking1 == a[1]-1) checking3 = a[1]-1;
            else checking3 = checking1+1;
            if(checking2 == a[0]-1) checking4 = a[0]-1;
            else checking4 = checking2+1;
            mini = min(mini , problem(prob[2][j],prob[1][checking1],prob[0][checking2]));
            mini = min(mini , problem(prob[2][j],prob[1][checking1],prob[0][checking4]));
            mini = min(mini , problem(prob[2][j],prob[1][checking3],prob[0][checking2]));
            mini = min(mini , problem(prob[2][j],prob[1][checking3],prob[0][checking4]));
        }
        cout<<mini<<"\n";
    }
    return 0;
}