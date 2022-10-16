#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    long long n,i,j;
    int t;
    cin>>t;
    while(t--)
    {
        long long a,b;
        cin>>n>>a>>b;
        if(a==1)
        {
            if((n-1)%b==0)
                cout<<"YES\n";
            else
                cout<<"NO\n";
            continue;
        }
        int ok=0;
        long long vlc=1;
        while(vlc<=n)
        {
            if((n-vlc)%b==0)
            {
                ok=1;
                break;
            }
            vlc=vlc*a;
        }
        if(ok)
                cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}