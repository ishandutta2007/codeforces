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
        int i,j,n,odd=0,even=0;
        string s;
        cin>>s;
        for(i=0;i<s.size();i++)
        {
            if(s.at(i)=='0')
                even++;
            else
                odd++;
        }
        int ded = min(even,odd);
        if(ded%2)
            cout<<"DA\n";
        else
            cout<<"NET\n";
    }
    return 0;
}