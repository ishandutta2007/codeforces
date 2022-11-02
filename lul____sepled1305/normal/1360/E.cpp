#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a,b,i,j;
        bool suc = true;
        cin>>a;
        b=a;
        string s[a];
        for(i=0;i<a;i++)
            cin>>s[i];
        for(i=0;i<a;i++)
        {
            for(j=0;j<b;j++)
            {
                if(s[i].at(j)=='1')
                {
                    if(i!=a-1 && j!=b-1)
                    {
                        if(s[i].at(j+1)!='1' && s[i+1].at(j)!='1')
                            suc = false;
                    }

                }
            }
        }
        if(!suc)
            cout<<"NO\n";
        else
            cout<<"YES\n";
    }
}