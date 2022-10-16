#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t,s;
    cin>>t;
    while(t--)
    {
        int a;
        cin>>a;
        int s=0;
        int cnt=0;
        for(int i=1;1;i+=2)
        {
            s+=i;
            ++cnt;
            if(s>=a)
                break;
        }
        cout<<cnt<<'\n';
    }
    return 0;
}