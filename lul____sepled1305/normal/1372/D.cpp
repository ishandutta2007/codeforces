#include<bits/stdc++.h>
using namespace std;
const int N = 4e5+10;
int n,i;
vector<int> v;
long long qsum[N];
long long odd = 0, even = 0;
long long maxi = 0;

int main()
{
    cin>>n;
    for(i=0;i<n;i++)
    {
        int a;
        cin>>a;
        if(i%2==0)
            even+=a,qsum[i]=even;
        else
            odd+=a,qsum[i]=odd;
        v.push_back(a);
    }
    for(i=0;i<n;i++)
    {
        if(i%2==1)
            even+=v[i],qsum[n+i]=even;
        else
            odd+=v[i],qsum[n+i]=odd;
        v.push_back(v[i]);
    }
    if(n!=1)
    {
        for(i=1; i<=n; i++)
        {
            long long cur = v[i]+v[i-1];
            cur+=qsum[i+n-3]-qsum[i];
            maxi = max(cur,maxi);
        }
        cout<<maxi;
    }
    else
    {
        cout<<v[0];
    }
    return 0;
}