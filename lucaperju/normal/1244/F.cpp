#include <bits/stdc++.h>

using namespace std;
int v[1000005];
int main()
{
    long long d,k,i,j,t,n,ki,pzi;
    cin>>n>>k;
    for(i=1;i<=n;++i)
    {
        char c;
        cin>>c;
        v[i]=(c=='B');
    }
    for(i=n+1;i<=4*n;++i)
        v[i]=v[i-n];
    for(i=3;i<=2*n+2;++i)
    {
        if(v[i]!=v[i-1] && v[i-1]==v[i-2])
        {
            for(j=i;v[j]!=v[j+1];++j){}
            --j;
            int dst=j-i+1;
            if(dst==0)
                continue;
            if(dst&1)
            {
                for(int y=i;y<=min(i+k-1,j);++y)
                    v[y]=v[i-1];
                for(int y=j;y>=max(j-k+1,i);--y)
                    v[y]=v[i-1];
                for(int y=i+k;y<=j-k;++y)
                    if(k&1)
                        v[y]=1-v[y];
            }
            else
            {
                for(int y=i;y<=min(i+k-1,(i+j)/2);++y)
                    v[y]=v[i-1];
                for(int y=j;y>=max(j-k+1,(i+j)/2+1);--y)
                    v[y]=v[j+1];
                for(int y=i+k;y<=j-k;++y)
                    if(k&1)
                        v[y]=1-v[y];
            }
            i=j+2;
        }
    }
    for(i=n+1;i<=2*n;++i)
    {
        if(v[i]==1)
            cout<<'B';
        else
            cout<<'W';
    }
    return 0;
}