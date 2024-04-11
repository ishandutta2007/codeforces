#include<bits/stdc++.h>
using namespace std;

string inp;

int solve()
{
    cin>>inp;

    int ret=10;

    for(int mask=0;mask<(1<<10);mask++)
    {
        bool go=1;

        for(int j=0;j<10;j++)
            if(inp[j]!='?')
            {
                bool should=(mask)&(1<<j);

                bool is=inp[j]-'0';

                if(should!=is)go=0;
            }

        if(go==0)continue;

        int score[2]={0,0};
        int remain[2]={5,5};

        for(int j=0;j<10;j++)
        {
            bool is=(mask)&(1<<j);

            score[j%2]+=is;
            remain[j%2]--;

            if(score[0]+remain[0]<score[1]||score[1]+remain[1]<score[0])
            {
                ret=min(ret,j+1);
                break;
            }
        }
    }
    return ret;
}

int main()
{
    int t;
    cin>>t;

    while(t)
    {
        t--;
        cout<<solve()<<endl;
    }

    return 0;
}