#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;

int n;

char inp[3][nmax];

int pos[3];

bool in(string s,int t)
{
    int pos=0;

    for(auto w:s)
    {
        if(w==inp[t][pos+1])
        {
            pos++;
        }
    }

    return pos>=2*n;
}

mt19937 rng(42);

void solve()
{
    /*
    n=3;
    for(int t=0;t<3;t++)
    {
        for(int i=1;i<=2*n;i++)
            inp[t][i]='0'+rng()%2;

        cout<<"inp: ";
        for(int i=1;i<=2*n;i++)cout<<inp[t][i];
        cout<<endl;
    }
    */


    cin>>n;

    for(int t=0;t<3;t++)
        for(int i=1;i<=2*n;i++)cin>>inp[t][i];

    memset(pos,0,sizeof(pos));

    string outp="";

    for(int w=1;w<=3*n&&pos[0]<2*n&&pos[1]<2*n&&pos[2]<2*n;w++)
    {
        char cur;
        int add=-1;

        for(char c='0';c<'2';c++)
        {
            int now=0;

            for(int t=0;t<3;t++)
                if(pos[t]+1<=2*n&&inp[t][pos[t]+1]==c)now++;

            if(now>add)
            {
                cur=c;
                add=now;
            }
        }

        outp.push_back(cur);

        for(int t=0;t<3;t++)
            if(pos[t]+1<=2*n&&inp[t][pos[t]+1]==cur)pos[t]++;

        //cout<<"w= "<<w<<" -> ";cout<<pos[0]<<" "<<pos[1]<<" "<<pos[2]<<endl;
    }

    int mx=-1;
    for(int t=0;t<3;t++)
        if(pos[t]<2*n)
        {
            if(mx==-1)mx=t;
            else if(pos[t]>pos[mx])mx=t;
        }

    while(mx>=0&&pos[mx]<2*n&&outp.size()<3*n)
    {
        outp.push_back(inp[mx][pos[mx]+1]);
        pos[mx]++;
    }

    while(outp.size()<3*n)outp.push_back('0');

    cout<<outp<<endl;

    assert(outp.size()==3*n);

    //cout<<in(outp,0)<<" "<<in(outp,1)<<" "<<in(outp,2)<<endl;
    int sum=in(outp,0)+in(outp,1)+in(outp,2);

    assert(sum>=2);
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