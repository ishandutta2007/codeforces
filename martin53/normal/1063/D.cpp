#include<bits/stdc++.h>
using namespace std;
const long long C=3e3;
long long n,k,l,r;
void no()
{
    cout<<"-1"<<endl;
    exit(0);
}
int main()
{
cin>>n>>l>>r>>k;
long long g=0;
if(l<=r)g=r-l+1;
else g=r+n-l+1;
if(k<g)no();

if(n>=C)//big n
{
    long long ans=-1;

    for(long long q=0;n*q<=k;q++)
    {
        long long k_=k-n*q-g;
        if(k_>=0)
        {
        long long t=(k_+n-g)/(q+1);

        //cout<<k_<<" "<<q<<" max t "<<t<<endl;

        long long g_=k_-t*q;
        if(g_>g||t>n||g_>t);
        else ans=max(ans,t);
        }
        k_++;
        if(k_<0)continue;

        long long t=(k_+n-g)/(q+1);

        //cout<<k_<<" "<<q<<" max t "<<t<<endl;

        long long g_=k_-t*q;
        if(g_>g||t>n||g_>t)continue;
        if(g_<1||t<1)continue;
        ans=max(ans,t);

        //cout<<q<<" -> "<<t<<" "<<g_<<endl;
    }
    cout<<ans<<endl;
    return 0;
}
else//small n
{
    long long ans=-1;
        for(long long t=0;t<=n;t++)
            for(long long g_=0;g_<=t&&g_<=g;g_++)
            {
            if(g_+n-g<t)continue;

            long long u=k-g-g_;
            long long v=n+t;
            if(u<0)continue;
            if(u%v)continue;

            ans=max(ans,t);
            }
        k++;

        for(long long t=1;t<=n;t++)
            for(long long g_=1;g_<=t&&g_<=g;g_++)
            {
            if(g_+n-g<t)continue;

            long long u=k-g-g_;
            long long v=n+t;
            if(u<0)continue;
            if(u%v)continue;

            ans=max(ans,t);
            }
    cout<<ans<<endl;
}
return 0;
}