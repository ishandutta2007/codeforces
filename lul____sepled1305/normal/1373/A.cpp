/**Ithea is a nice girl.**/
#include<bits/stdc++.h>
using namespace std;
int T;

int main()
{
    /**ios_base::sync_with_stdio(false);
    cin.tie(NULL);**/

    cin>>T;
    while(T--)
    {
        long long a,b,x;
        cin>>a>>x>>b;
        if(a<b)
            cout<<1<<" ";
        else
            cout<<-1<<" ";
        if(b>=a*x)
            cout<<-1<<"\n";
        else
            cout<<x<<"\n";
    }
    return 0;
}