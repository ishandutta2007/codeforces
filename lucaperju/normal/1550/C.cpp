#include <bits/stdc++.h>

using namespace std;
int v[200005];
bool eok (int a, int b)
{
    if(b-a<=1)
        return true;
    if(a+2==b)
    {
        --b;
        int c=b+1;
        if(v[a]<=v[b] && v[b]<=v[c])
            return false;
        if(v[a]>=v[b] && v[b]>=v[c])
            return false;
        return true;
    }
    int c,d;
    b=a+1;
    c=b+1;
    d=c+1;
    if(v[a]<=v[b] && v[b]<=v[c])
        return false;
    if(v[a]>=v[b] && v[b]>=v[c])
        return false;
    if(v[a]<=v[b] && v[b]<=v[d])
        return false;
    if(v[a]>=v[b] && v[b]>=v[d])
        return false;
    if(v[a]<=v[c] && v[c]<=v[d])
        return false;
    if(v[a]>=v[c] && v[c]>=v[d])
        return false;
    if(v[b]<=v[c] && v[c]<=v[d])
        return false;
    if(v[b]>=v[c] && v[c]>=v[d])
        return false;
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t,s;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int i;
        for(i=1;i<=n;++i)
            cin>>v[i];
        long long cnt=0;
        for(i=1;i<=n;++i)
        {
            if(eok(i,i))
                ++cnt;
            if(i+1>n)
                continue;
            if(eok(i,i+1))
                ++cnt;
            if(i+2>n)
                continue;
            if(eok(i,i+2))
                ++cnt;
            if(i+3>n)
                continue;
            if(eok(i,i+3))
                ++cnt;
        }
        cout<<cnt<<'\n';
    }
    return 0;
}