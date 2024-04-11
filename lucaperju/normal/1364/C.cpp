#include <bits/stdc++.h>

using namespace std;
int v[100005];
int rz[100005];
int ocp[1000005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    unsigned long long m,k,t,i,j,p,mxx=0,s,q,nr1=0,nr2=0,nr3=0,n;
    cin>>n;
    for(i=1;i<=n;++i)
        cin>>v[i];
    v[0]=0;
    for(i=1;i<=n;++i)
    {
        if(v[i]!=v[i-1])
            rz[i]=v[i-1],ocp[v[i]]=ocp[v[i-1]]=1;
    }
    j=1;
    for(i=1;i<=n;++i)
    {
        if(v[i]==v[i-1])
        {
            while(ocp[j])
                ++j;
            rz[i]=j;
            ++j;
        }
    }
    for(i=1;i<=n;++i)
        cout<<rz[i]<<' ';
    return 0;
}