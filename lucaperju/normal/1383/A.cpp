#include <bits/stdc++.h>
using namespace std;
char a[100005],b[100005];
int fv[35][35];
int main()
{
    long long n,m,i,j,x,y,k,t,l,r;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cin>>(a+1)>>(b+1);
        for(i=1;i<=n;++i)
        {
            if(a[i]>b[i])
                break;
        }
        if(i<=n)
        {
            cout<<"-1\n";
            continue;
        }
        for(i=1;i<=30;++i)
            for(j=1;j<=30;++j)
                fv[i][j]=0;
        for(i=1;i<=n;++i)
        {
            int ca=a[i]-'a'+1;
            int cb=b[i]-'a'+1;
            if(ca!=cb)
                fv[ca][cb]=1;
        }
        int cnt=0;
        for(i=1;i<=30;++i)
        {
            for(j=i+1;j<=30;++j)
                if(fv[i][j])
                    break;
            if(j==31)
                continue;
            ++cnt;
            for(k=j+1;k<=30;++k)
                fv[j][k]|=fv[i][k];
        }
        cout<<cnt<<'\n';
    }
    return 0;
}