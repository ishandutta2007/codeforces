#include<bits/stdc++.h>
using namespace std;
const int nmax=1e2+5;
int n,arr[nmax];
long long k;
long long output;
long long divs(long long d)//decreasing
{
    long long ret=0;
    for(int i=1;i<=n;i++)
        ret=ret+(arr[i]+d-1)/d;

    if(ret*d<=k)output=max(output,d);

    return ret;
}
//f(x)=x - increasing
void solve(long long l,long long l_val,long long r,long long r_val)
{
    //cout<<"solve "<<l<<" "<<l_val<<" "<<r<<" "<<r_val<<endl;
    if(r<=output)return;

    if(l_val==r_val)
    {
        long long mx=k/l_val;
        if(l<=mx)
        {
            output=max(output,mx);
        }
        return;
    }

    if(r-l<=1)return;
    if(l*r_val>k)return;

    long long av=(l+r)/2;
    long long av_val=divs(av);

    solve(av,av_val,r,r_val);
    solve(l,l_val,av,av_val);
}
int main()
{
cin>>n>>k;
for(int i=1;i<=n;i++)
{
    cin>>arr[i];
    k=k+arr[i];
}

output=1;
solve(1,divs(1),k+1,divs(k+1));

cout<<output<<endl;
return 0;
}