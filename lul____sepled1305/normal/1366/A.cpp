#include<bits/stdc++.h>
using namespace std;
int T;

int main()
{
    cin>>T;
    while(T--)
    {
        int a,b,ans;
        cin>>a>>b;
        if(b>a) swap(a,b);
        if(a>2*b) cout<<b<<"\n";
        else cout<<(a+b)/3<<"\n";
    }
    return 0;
}