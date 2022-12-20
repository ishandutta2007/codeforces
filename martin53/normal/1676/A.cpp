#include<bits/stdc++.h>
using namespace std;

bool solve()
{
    string inp;

    cin>>inp;

    return inp[0]+inp[1]+inp[2]==inp[3]+inp[4]+inp[5];
}

int main()
{
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