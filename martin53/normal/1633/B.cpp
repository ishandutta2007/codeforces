#include<bits/stdc++.h>
using namespace std;

int solve()
{
    string inp;

    int cnt[2]={0,0};

    cin>>inp;

    for(auto w:inp)
    {
        cnt[w-'0']++;
    }

    return min(cnt[0],cnt[1])-(cnt[0]==cnt[1]);
}

int main()
{
    int t;
    cin>>t;

    while(t)
    {
        t--;
        cout<<solve()<<"\n";
    }
}