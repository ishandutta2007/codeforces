/** Mion Best Girl **/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
using pii = pair<int,int>;
using pll = pair<ll,ll>;
const int MOD = 1e9+7;
const int N = 1e5+10;
 
int n,i;
const int chtholly = 0;
vector<int> v;
int ans[N];
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cin>>n;
    for(i=0;i<n;i++)
    {
        int a;
        cin>>a;
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    for(i=0;i<n/2;i++)
    {
        int val = 2*i +1;
        ans[val] = v[i];
    }
    int counti = 0;
    for(i = n/2; i <n; i++)
    {
        ans[counti] = v[i];
        counti+=2;
    }
    counti = 0;
    for(i=1;i<n-1;i++)
    {
        if(ans[i] < ans[i-1] && ans[i] < ans[i+1])
            counti++;
    }
    cout<<counti<<endl;
    for(i=0;i<n;i++)
        cout<<ans[i]<<' ';
    return chtholly;
}