#include <bits/stdc++.h>
using namespace std;
char v[55];
char idk[10];
int n;
char v1[55];
bool verif (int pz)
{
    int i,j;
    for(i=1;i<=n;++i)
        v1[i]=v[i];
    for(i=0;i<=6;++i)
    {
        if(v[i+pz]!=idk[i] && v[i+pz]!='?')
            return 0;
        v1[i+pz]=idk[i];
    }
    for(i=1;i<=n;++i)
        if(v1[i]=='?')
            v1[i]='d';
    int cnt=0;
    for(i=1;i<=n;++i)
    {
        if(i+6>n)
            break;
        for(j=0;j<=6;++j)
        {
            if(v1[i+j]!=idk[j] && v1[i+j]!='?')
                break;
        }
        if(j==7)
            ++cnt;
    }
    if(cnt==1)
        return 1;
    else
        return 0;
}
int main()
{
    long long m,i,j,x,y,k,t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=1;i<=n;++i)
            cin>>v[i];
        idk[0]='a';
        idk[1]='b';
        idk[2]='a';
        idk[3]='c';
        idk[4]='a';
        idk[5]='b';
        idk[6]='a';
        int pz;
        for(pz=1;pz<=n-6;++pz)
        {
            if(verif(pz))
                break;
        }
        if(pz==n-5)
        {
            cout<<"NO\n";
            continue;
        }
        cout<<"YES\n";
        for(i=0;i<=6;++i)
            v[pz+i]=idk[i];
        for(i=1;i<=n;++i)
        {
            if(v[i]=='?')
                v[i]='d';
        }
        for(i=1;i<=n;++i)
            cout<<v[i];
        cout<<'\n';
    }
    return 0;
}