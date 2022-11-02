#include<bits/stdc++.h>
using namespace std;

int counti,t,i;
int one, zero;
string s;

int main()
{
    cin>>t;
    while(t--)
    {
        one = 0;
        zero =0;
        cin>>s;
        for(i=0;i<s.size();i++)
        {
            if(s.at(i)=='1')
                one =1;
            if(s.at(i)=='0')
                zero=1;
        }
        if(one+zero ==2)
            for(i=0;i<s.size();i++)
                cout<<"01";
        else
            for(i=0;i<s.size()+1;i++)
                cout<<s.at(0);
        cout<<"\n";
        }
}