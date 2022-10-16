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
        int a,b;
        cin>>a>>b;
        long long pas=1LL<<32;
        k=0;
        while(pas)
        {
            if(verif(a,b,k+pas))
                k+=pas;
            pas>>=1LL;
        }
        cout<<k<<'\n';
    }
    return 0;
}