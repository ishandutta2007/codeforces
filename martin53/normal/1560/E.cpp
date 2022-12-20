#include<bits/stdc++.h>
using namespace std;

int cnt[26];

void solve()
{
    string inp;
    cin>>inp;

    memset(cnt,0,sizeof(cnt));

    string outp="";

    for(int i=inp.size()-1;i>=0;i--)
    {
        int cur=inp[i]-'a';

        cnt[cur]++;

        if(cnt[cur]==1)outp.push_back(inp[i]);
    }

    reverse(outp.begin(),outp.end());

    //cout<<outp<<endl;

    int SZ=0;

    for(int i=0;i<outp.size();i++)
    {
        int cur=outp[i]-'a';

        if(cnt[cur]%(i+1))
        {
            cout<<-1<<endl;
            return;
        }

        SZ+=cnt[cur]/(i+1);
    }

    string original="";
    for(int i=0;i<SZ;i++)original.push_back(inp[i]);

    int where=0;
    for(int t=0;t<outp.size();t++)
    {
        for(auto w:original)
        {
            if(cnt[w-'a'])
            {
                if(where==inp.size())
                {
                    cout<<-1<<endl;
                    return;
                }

                if(inp[where]!=w)
                {
                    cout<<-1<<endl;
                    return;
                }

                where++;
            }
        }

        cnt[outp[t]-'a']=0;
    }

    cout<<original<<" "<<outp<<endl;
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