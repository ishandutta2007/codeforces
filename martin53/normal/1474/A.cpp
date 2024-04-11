#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    string inp;

    cin>>n>>inp;

    int lst=0;

    for(auto w:inp)
    {
        for(int d=2;d>=0;d--)
            if(lst!=d&&d-(w-'0')<=1)
            {
                cout<<d-(w-'0');
                lst=d;
                break;
            }
    }

    cout<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    int t;
    cin>>t;

    while(t)
    {
        t--;

        solve();
    }

    return 0;
}