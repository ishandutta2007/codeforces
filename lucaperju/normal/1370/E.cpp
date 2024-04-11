#include <bits/stdc++.h>
using namespace std;
char a[1000006],b[1000006];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int i,j,n;
    cin>>n;
    cin>>(a+1)>>(b+1);
    int sm=0,sM=0,bm=0,bM=0;
    int s=0;
    for(i=1;i<=n;++i)
    {
        s+=a[i];
        s-=b[i];
    }
    if(s!=0)
    {
        cout<<-1;
        return 0;
    }
    for(i=1;i<=n;++i)
    {
        if(a[i]>b[i])
        {
            ++sm;
            ++sM;
        }
        if(a[i]<b[i])
        {
            --sm;
            --sM;
        }
        if(sm<bm)
            bm=sm;
        if(sM>bM)
            bM=sM;
        sm=min(sm,0);
        sM=max(sM,0);
    }
    cout<<max(bM,-bm);
    return 0;
}