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
        int n;
        cin>>n;
        if(n%4==0)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}