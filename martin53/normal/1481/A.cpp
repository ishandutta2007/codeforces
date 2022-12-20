#include<bits/stdc++.h>
using namespace std;

bool solve()
{
    int x,y;
    cin>>x>>y;

    string inp;
    cin>>inp;

    int x_min=0,x_max=0,y_min=0,y_max=0;

    for(auto w:inp)
        if(w=='U')y_max++;
        else if(w=='D')y_min--;
        else if(w=='L')x_min--;
        else x_max++;

    return x_min<=x&&x<=x_max&&y_min<=y&&y<=y_max;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();

    int t;
    cin>>t;

    while(t)
    {
        t--;

        if(solve())cout<<"YES\n";
        else cout<<"NO\n";
    }

    return 0;
}