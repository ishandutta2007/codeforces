#include <bits/stdc++.h>
using namespace std;
char v[500005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        if(n==2)
        {
            cout<<"Bob\n";
            continue;
        }
        if(n%2==1)
            cout<<"Bob\n";
        else
        {
            int cnt=0;
            int cn=n;
            int ok=0;
            while(n>1)
            {
                if(n%2)
                    ok=1;
                n/=2;
                ++cnt;
            }
            if(!ok && cn>4 && cnt%2==1)
                cout<<"Bob\n";
            else
                cout<<"Alice\n";
        }
    }
    return 0;
}