#include <bits/stdc++.h>
using namespace std;
long long a[200005],b[200005];
int main ()
{
    long long n,m,ta,tb,k,i,j;
    long long mn=0LL;
    cin>>n>>m>>ta>>tb>>k;
    for(i=1;i<=n;++i)
        cin>>a[i];
    for(j=1;j<=m;++j)
        cin>>b[j];
    int st=1;
    for(i=0;i<=k;++i)
    {
        if(i+1>n)
        {
            cout<<-1;
            return 0;
        }
        int vlst=a[i+1]+ta;
        while(st<=m && b[st]<vlst)
            ++st;
        int cst=st+k-i;
        if(cst>m)
        {
            cout<<-1;
            return 0;
        }
        mn=max(mn,b[cst]+tb);
    }
    cout<<mn;
    return 0;
}