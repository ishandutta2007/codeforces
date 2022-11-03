#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
bool x;
int main()
{
    string a[1001];
    int n;
    cin>>n;
    x=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(!x)
        {
            if(a[i][0]=='O' && a[i][1]=='O')
            {
                a[i][0]='+';
                a[i][1]='+';
                x=true;
            }
            else if(a[i][3]=='O' && a[i][4]=='O')
            {
                a[i][3]='+';
                a[i][4]='+';
                x=true;
            }
        }
    }
    if(x)
    {
        cout<<"YES"<<endl;
        for(int i=0;i<n;i++)
            cout<<a[i]<<endl;
    }
    else
        cout<<"NO"<<endl;
}