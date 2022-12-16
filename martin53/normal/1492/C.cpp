#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;

pair<int,string> inp[2];

int pref[nmax],suff[nmax];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();

    cin>>inp[0].first>>inp[1].first;
    cin>>inp[0].second>>inp[1].second;

    int pos=0;

    int where=0;

    for(auto w:inp[1].second)
    {
        while(inp[0].second[pos]!=w)pos++;

        pref[where]=pos;

        where++;
        pos++;
    }

    reverse(inp[1].second.begin(),inp[1].second.end());

    pos=inp[0].second.size()-1;
    where=inp[1].second.size();

    for(auto w:inp[1].second)
    {
        where--;

        while(inp[0].second[pos]!=w)pos--;

        suff[where]=pos;
        pos--;
    }

    int outp=0;
    for(int i=1;i<inp[1].second.size();i++)
        outp=max(outp,suff[i]-pref[i-1]);

    cout<<outp<<endl;

    return 0;
}