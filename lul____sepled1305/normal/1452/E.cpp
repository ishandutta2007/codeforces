#include<bits/stdc++.h>
using namespace std;
 
struct segment
{
    int l, r;
 
    segment(int a, int b)
    {
        l=a,r=b;
    }
};
 
int intersect(segment a, segment b)
{
    if(a.l > b.l)
        swap(a,b);
 
    if(a.r < b.l)
        return 0;
    if(a.r > b.r)
        return (b.r-b.l+1);
    return (a.r-b.l+1);
}
 
int line_sweep(int n,int m,int k,vector<segment> v, int st)
{
    int dp[2*n];
    int i,j,sum = 0;;
    for(i=0;i<2*n;i++)
        dp[i] = 0;
    segment tester = segment(st,st+k-1);
    for(i=0;i<m;i++)
    {
        int val = intersect(tester,v[i]);
        sum += val;
        if(val == k || val == v[i].r-v[i].l+1 || intersect(tester,v[i]) > intersect(segment(st+1,st+k),v[i]) || st > v[i].r)
            continue;
        else
        {
            dp[max(v[i].l-(k-val)+1,1)] += 1;
            dp[v[i].r-(val)+2] += 1;
            dp[v[i].l+1] -= 1;
            dp[max(v[i].r-k+2,1)] -= 1;
        }
    }
    int cur = 0;
    for(i=1;i<2*n;i++)
    {
        cur+=dp[i];
        dp[i] = cur + dp[i-1];
    }
 
    int ww = 0, maxi = 0;
    for(i=st+1;i<2*n-k;i++)
    {
        ww = dp[i];
        maxi = max(maxi, ww);
    }
    return sum+maxi;
}
 
void solve()
{
    int n,m,k,i,j,a,b,maxi = 0;
    cin>>n>>m>>k;
    vector<segment> v;
    for(i=0;i<m;i++)
    {
        cin>>a>>b;
        v.push_back(segment(a,b));
    }
    for(i=1;i<=n;i++)
    {
        int cur = line_sweep(n,m,k,v,i);
        maxi = max(maxi,cur);
    }
    cout<<maxi;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();
    return 0;
}