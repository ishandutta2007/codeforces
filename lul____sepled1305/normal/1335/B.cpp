#include<bits/stdc++.h>
using namespace std;
int i,j,k,n,t,a,b;
char ll='a';

int main()
{
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n>>a>>b;
        for(j=0;j<n;j++)
        {
            if(j%a<=b-1)
            {
                ll = 'a'+j%a;
                cout<<ll;
            }
            else
            {
                cout<<"a";
            }
        }
        cout<<"\n";
    }
    return 0;
}