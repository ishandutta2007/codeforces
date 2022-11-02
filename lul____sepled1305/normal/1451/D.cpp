#include<bits/stdc++.h>
using namespace std;

void solve()
{
    long long d,k,i;
    long long last = 0;
    cin>>d>>k;
    for(i=0;i<d;i++)
    {
        if(2*(i+1)*(i+1)>d*d)
        {
            last = i;
            break;
        }
    }
    last = (last/k)*k;
    if(last*last+(last+k)*(last+k) <= d*d)
    {
        cout<<"Ashish\n";
    }
    else
        cout<<"Utkarsh\n";
}

int main()
{
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}