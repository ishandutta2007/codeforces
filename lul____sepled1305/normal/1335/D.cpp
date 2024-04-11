#include<bits/stdc++.h>
using namespace std;
string s;
int i,j,k,t;

int main()
{
    cin>>t;
    for(i=0;i<t;i++)
    {
        for(j=0;j<9;j++)
        {
            cin>>s;
            for(k=0;k<9;k++)
            {
                if(s.at(k)=='1') cout<<2;
                else cout<<s.at(k);
            }
            cout<<"\n";
        }
    }
}