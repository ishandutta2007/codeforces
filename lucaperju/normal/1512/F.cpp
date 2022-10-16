#include <bits/stdc++.h>
using namespace std;
long long a[200003],b[200003];
int main()
{
    ios_base::sync_with_stdio(false);
    long long i,t,p,j;
    cin>>t;
    while(t--)
    {
        long long n,c;
        cin>>n>>c;
        long long sc=0;
        for(i=1;i<=n;++i)
            cin>>a[i];
        for(i=1;i<n;++i)
            cin>>b[i];
        long long mn=(c-sc-1)/a[1]+1;
        long long cntc=0;
        for(i=2;i<=n;++i)
        {
            ++cntc;
            if(sc>=b[i-1])
                sc-=b[i-1];
            else
            {
                long long vlc=(b[i-1]-sc-1)/a[i-1]+1;
                cntc+=vlc;
                sc=sc+vlc*1LL*a[i-1]-b[i-1];
            }
            mn=min(mn,cntc+(c-sc-1)/a[i]+1);
        }
        cout<<mn<<'\n';
    }
	return 0;
}