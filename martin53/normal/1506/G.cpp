#include<bits/stdc++.h>
using namespace std;

string inp;

bool seen[26];

string outp;

bool in[26],mem_seen[26];

bool go()
{
    memset(in,0,sizeof(in));

    for(int i=0;i<26;i++)mem_seen[i]=seen[i];

    int remain=0;

    for(auto w:inp)
    {
        if(remain<outp.size())
        {
            if(w==outp[remain])remain++;
        }
        else
        {
            if(mem_seen[w-'a'])mem_seen[w-'a']=0;
        }
    }

    if(remain!=outp.size())return 0;
    for(int i=0;i<26;i++)
        if(mem_seen[i])return 0;
    return 1;
}

void solve()
{
    cin>>inp;

    memset(seen,0,sizeof(seen));

    int t=0;

    for(auto w:inp)
        if(seen[w-'a']==0)
        {
            t++;
            seen[w-'a']=1;
        }

    outp="";

    for(int j=0;j<t;j++)
    {
        for(int i=25;i>=0;i--)
            if(seen[i])
            {
                seen[i]=0;

                outp.push_back(i+'a');

                if(go())break;

                seen[i]=1;

                outp.pop_back();
            }
    }

    cout<<outp<<endl;
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
        solve();
    }

    return 0;
}