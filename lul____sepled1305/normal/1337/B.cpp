#include<bits/stdc++.h>
using namespace std;
int i,t,m,n,hit;

int main()
{
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>hit>>m>>n;
        while(hit>20 && m>0)
        {
            hit=hit/2 +10;
            m--;
        }
        if(hit <=10*n)
        {
            cout<<"YES\n";
        }
        else
        {
            cout<<"NO\n";
        }
    }
    return 0;
}