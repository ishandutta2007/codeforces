/**Nephren is the best girl**/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
using pii = pair<int,int>;
using pll = pair<ll,ll>;
const int MOD = 1e9+7;
const int chtholly = 0;
int T;

int main()
{
    /**ios_base::sync_with_stdio(false);
    cin.tie(NULL);**/

    cin>>T;
    while(T--)
    {
        long long n,k,i,quick;
        int cased;
        pll arr[2];
        cin>>n>>k;
        cin>>arr[0].first>>arr[0].second;
        cin>>arr[1].first>>arr[1].second;
        sort(arr,arr+2,greater<pii>());
        if(arr[0].first<=arr[1].second)
            cased = 1;
        else
            cased = 2;

        if(cased == 1)
        {
            quick = n*(max(arr[0].second,arr[1].second)-min(arr[0].first,arr[1].first));
            long long get = n*(min(arr[0].second,arr[1].second)-max(arr[1].first,arr[0].first));
            if(quick>=k && k>get)
                cout<<k-get<<"\n";
            else if(k<=get)
                cout<<0<<"\n";
            else
                cout<<quick-get + 2*(k-quick)<<"\n";
        }
        else
        {
            quick = (2*(max(arr[0].second,arr[1].second)-min(arr[0].first,arr[1].first))+arr[0].first+arr[1].first - arr[0].second - arr[1].second);
            long long get  =(max(arr[0].second,arr[1].second)-min(arr[0].first,arr[1].first));
            long long mul = k/get;
            if(mul >= n )
            {
                cout<<(k-(n*get))*2 + n*quick<<"\n";
            }
            else
            {
                long long can1 = 1e18;
                if(mul>0)
                    can1 =  (k-(mul*get))*2 + mul*quick;
                long long can2 = mul*quick + (arr[0].first - arr[1].second) + k-(mul*get);
                cout<<min(can1,can2)<<"\n";
            }
        }
    }
    return chtholly;
}

/**
    I lied. Ithea is better than Nephren.
    JK
**/