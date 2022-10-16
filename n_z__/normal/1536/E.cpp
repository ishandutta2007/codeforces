#include<bits/stdc++.h>
using namespace std;
const int p=1e9+7;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        int num=0;
        for(int x=1;x<=n*m;x++)
        {
            char c;
            cin>>c;
            num+=(c=='#');
        }
        int ans=1;
        for(int x=1;x<=num;x++)ans<<=1,ans%=p;
        if(num==n*m)ans--;
        cout<<ans<<endl;
    }
}