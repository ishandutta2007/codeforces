#include<bits/stdc++.h>
using namespace std;
int T;

int main()
{
    cin>>T;
    while(T--)
    {
        int n ,i;
        cin>>n;
        int cur = n;
        for(i=n-1;i>0;i--)
        {
            cur = (cur+i+1)/2;
        }
        cout<<cur<<endl;
        cur = n;
        for(i=n-1;i>0;i--)
        {
            cout<<cur<<' '<<i<<endl;
            cur = (cur+i+1)/2;
        }
    }
}