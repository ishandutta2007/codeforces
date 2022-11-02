#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
int n,t,k,ans,i,j,maxi,ver;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>t;
    while(t--)
    {
        ans=0;
        maxi=0;
        ver=0;
        cin>>n>>k;
        vector<int> v;
        int arr[n], quick[n];
        for(i=0;i<n;i++)
        {
            cin>>j;
            v.pb(j);
            arr[i] = 0;
        }
        for(i=1;i<n-1;i++)
        {
            if(v[i]>v[i-1] && v[i]>v[i+1])
                arr[i] = 1;
        }
        quick[0] = arr[0];
        for(i=1;i<n;i++)
        {
            quick[i] = quick[i-1] + arr[i];
        }
        i=0;
        while(i+k-1<n)
        {
            ans = quick[i+k-2]-quick[i];
            if(ans>maxi)
            {
                maxi = ans;
                ver = i;
            }
            i++;
        }
        cout<<maxi+1<<" "<<ver+1<<"\n";
    }
    return 0;
}