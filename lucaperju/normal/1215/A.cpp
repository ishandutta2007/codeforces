#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    long long n,i,j,m,k=0,t,s=0;
    int a1,a2,k1,k2;
    cin>>a1>>a2>>k1>>k2>>n;
    cout<<max(0LL,n-(a1*(k1-1)+a2*(k2-1)))<<' ';
    if(k1>k2)
    {
        swap(a1,a2);
        swap(k1,k2);
    }
    while(a1 && n>=k1)
    {
        ++s;
        --a1;
        n-=k1;
    }
    while(a2 && n>=k2)
    {
        ++s;
        --a2;
        n-=k2;
    }
    cout<<s;
    return 0;
}