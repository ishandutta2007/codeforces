#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        int i,j,ans=0;
        for(i=0;i<s.size();i++)
        {
            if(s.at(i)!='0')
                ans++;
        }
        cout<<ans<<"\n";
        for(i=0;i<s.size();i++)
        {
            if(s.at(i)!='0')
            {
                cout<<s.at(i);
                j=i+1;
                while(j<s.size())
                {
                    cout<<"0";
                    j++;
                }
            }
            cout<<" ";
        }
        cout<<"\n";
    }
    return 0;
}