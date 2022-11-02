#include<bits/stdc++.h>
using namespace std;
int i,j,k,n,m,t;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>t;
    while(t--)
    {
        int ans=1e9;
        cin>>n>>k;
        const int K = 2*k+10;
        int maxi[K];
        int mini[K];
        int center[K];
        int arr[n];
        for(i=0;i<n;i++)
            cin>>arr[i];
        for(i=0;i<K;i++)
        {
            maxi[i]=0;
            mini[i]=0;
            center[i] = 0;
        }
        for(i=0;i<n/2;i++)
        {
            int mid = arr[i] + arr[n-1-i];
            center[mid]++;
            maxi[max(arr[i],arr[n-1-i]) + k +1]++;
            mini[min(arr[i],arr[n-1-i])]++;
        }
        int quick_mini[K], quick_maxi[K];
        quick_maxi[0] = maxi[0]; quick_mini[0] = mini[0];
        for(i=1;i<K;i++)
        {
            quick_maxi[i] = quick_maxi[i-1] + maxi[i];
            quick_mini[i] = quick_mini[i-1] + mini[i];
        }
        for(i=1;i<K-1;i++)
        {
            int val = n + (-quick_mini[i-1] + quick_maxi[i]) - center[i];
            if(val<ans)
            {
                ans=val;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}