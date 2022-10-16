#include <bits/stdc++.h>
using namespace std;
int rz[10004];
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n,i,j,k,t;
    cin>>n;
    int st=1,dr=n;
    while(st<dr)
    {
        cout<<"? "<<st<<' '<<dr<<'\n';
        cout.flush();
        int ab;
        cin>>ab;
        cout<<"? "<<dr<<' '<<st<<'\n';
        cout.flush();
        int ba;
        cin>>ba;
        if(ab>ba)
        {
            rz[st]=ab;
            ++st;
        }
        else
        {
            rz[dr]=ba;
            --dr;
        }
    }
    int s=0;
    for(i=1;i<=n;++i)
        s+=rz[i];
    rz[st]=n*1LL*(n+1LL)/2LL-s;
    cout<<"! ";
    for(i=1;i<=n;++i)
        cout<<rz[i]<<' ';
    cout<<'\n';
    cout.flush();
    return 0;
}