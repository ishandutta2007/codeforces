#include <bits/stdc++.h>
using namespace std;
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t,i,j,k;
    cin>>t;
    while(t--)
    {
        int n,a,b;
        cin>>a>>b;
        if(a>b)
            swap(a,b);
        a=b-a;
        int cnt=a/10;
        int rz=cnt;
        a-=cnt*10;
        if(a>=1)
            ++rz;
        cout<<rz<<'\n';
    }
}