#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
char c[500];
int main()
{
    ios_base::sync_with_stdio(false);cin.tie();cout.tie();
    long long n,k,i,j,s=0,m,cnt=0,cur,t;
    cin>>t;
    while(t--)
    {
        long long a,b;
        cin>>a>>b;
        if(b==9)
            cout<<a*9LL<<'\n';
        else
        {
            --a;
            cout<<a*9LL+b<<'\n';
        }
    }
    return 0;
}