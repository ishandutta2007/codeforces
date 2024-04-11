#include <bits/stdc++.h>
using namespace std;
long long rz[1000003];
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    long long q,m,i,j,l,r,t,n;
    cin>>n;
    long long lst=0,eq=0;
    long long a;
    cin>>a;
    lst=a;
    for(i=2;i<=n;++i)
    {
        cin>>a;
        if(a==lst+1)
        {
            lst=a;
            continue;
        }
        long long k=0,pas=(1LL<<39);
        while(pas)
        {
            long long kk=k+pas;
            /// k = kk daca ar mai cadea in continuare
            long long nlst=lst+kk/(i-1)+((eq+kk%(i-1))>=(i-1));
            if(nlst+2<=a-kk)
                k=kk;
            pas>>=1;
        }
        ++k;
        eq=(eq+(a-lst)-1+i)%i;
        lst=a-k;
    }
    ++eq;
    rz[n]=lst;
    for(i=n-1;i>=1;--i)
    {
        if(i==eq-1)
            rz[i]=rz[i+1];
        else
            rz[i]=rz[i+1]-1;
    }
    for(i=1;i<=n;++i)
        cout<<rz[i]<<' ';
    return 0;
}