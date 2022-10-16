#include <bits/stdc++.h>
using namespace std;
long long v[200003];
vector<long long>vc;
int main()
{
    ios_base::sync_with_stdio(false);
    long long t,a,k,x,b,i,n;
    cin>>n>>k>>x;
    for(i=1;i<=n;++i)
        cin>>v[i];
    sort(v+1,v+n+1);
    int cnt=1;
    for(i=1;i<n;++i)
    {
        if(v[i+1]-v[i]>x)
        {
            vc.push_back(v[i+1]-v[i]);
            ++cnt;
        }
    }
    sort(vc.begin(),vc.end());
    for(i=0;i<vc.size();++i)
    {
        long long need=(vc[i]-1)/x;
        if(need<=k)
        {
            k-=need;
            --cnt;
        }
        else break;
    }
    cout<<cnt;
	return 0;
}