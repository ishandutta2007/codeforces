#include <bits/stdc++.h>
using namespace std;
int v[100003];
int rz[100003];
int main()
{
    ios_base::sync_with_stdio(false);
    long long q,t,k,m,i,j,n;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        --k;
        for(i=n;i>1;--i)
        {
            if(k%2LL)
                v[i]=1;
            else
                v[i]=0;
            k/=2LL;
        }
        if(k!=0)
        {
            cout<<"-1\n";
            continue;
        }
        int pzc=n;
        int cnt;
        while(pzc>0)
        {
            cnt=0;
            for(i=pzc;v[i]==1;--i)++cnt;
            for(j=pzc;j>=i;--j)
            {
                rz[j]=pzc-cnt;
                --cnt;
            }
            pzc=i-1;
        }
        for(i=1;i<=n;++i)
            cout<<rz[i]<<' ';
        cout<<'\n';
    }
	return 0;
}