#include<bits/stdc++.h>
using namespace std;

long long solve()
{
    string inp;

    cin>>inp;

    int prv[2][2];

    prv[0][0]=-1;
    prv[0][1]=-1;
    prv[1][0]=-1;
    prv[1][1]=-1;

    int mx=0;

    long long outp=0;

    for(int i=0;i<inp.size();i++)
    {
        if(inp[i]!='?')
        {
            int c=inp[i]-'0';

            mx=max(mx,prv[!c][i%2]+1);
            mx=max(mx,prv[c][!(i%2)]+1);

            prv[c][i%2]=i;
        }

        outp+=i-mx+1;

        //cout<<i<<" -> "<<mx<<" "<<outp<<endl;
    }

    return outp;
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

    return 0;
}