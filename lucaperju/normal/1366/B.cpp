#include <bits/stdc++.h>

using namespace std;
bool verif (int a, int b, long long cat)
{
    a-=cat;
    b-=cat;
    if(a>=0 && b>=0 && a+b>=cat)
        return true;
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    unsigned long long m,k,t,i,j,p,mxx=0,s,q,nr1=0,nr2=0,nr3=0;
    cin>>t;
    long long n;
    while(t--)
    {
        long long x;
        cin>>n>>x>>m;
        long long st=x,dr=x;
        for(i=1;i<=m;++i)
        {
            long long a,b;
            cin>>a>>b;
            if(a<=dr && dr<=b || a<=st && st<=b)
            {
                st=min(st,a);
                dr=max(dr,b);
            }
        }
        cout<<dr-st+1<<'\n';
    }
    return 0;
}