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
        int n,i;
        string s;
        int first1 = -1;
        int last0=-1;
        cin>>n;
        cin>>s;
        for(i=0;i<n;i++)
        {
            if(s.at(i)=='0')
                last0 = i;
            if(s.at(i)=='1' && first1==-1)
                first1 = i;
        }
        if(first1==-1 || last0==-1 || last0<first1)
        {
            for(i=0;i<n;i++)
                cout<<s.at(i);
        }
        else
        {
            for(i=0;i<first1;i++)
                cout<<s.at(i);
            cout<<"0";
            for(i=last0+1;i<n;i++)
                cout<<s.at(i);
        }
        cout<<"\n";
    }
    return 0;
}