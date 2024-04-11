#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,i;
    char s;
    cin>>a>>b;
    for(i=1;i<=a*b;i++)
    {
        cin>>s;
        if(s=='C'||s=='M'||s=='Y')
        {
            cout<<"#Color";
            return 0;
        }
    }
    cout<<"#Black&White";
    return 0;
}