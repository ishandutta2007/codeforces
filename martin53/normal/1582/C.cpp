#include<bits/stdc++.h>
using namespace std;

int solve()
{
    int n;
    cin>>n;

    string inp;

    cin>>inp;

    int outp=-1;

    for(char cur='a';cur<='z';cur++)
    {
        int score=0;

        int l=0,r=n-1;

        while(l<r)
        {
            if(inp[l]==inp[r])
            {
                l++;
                r--;
                continue;
            }

            if(inp[l]==cur)
            {
                score++;
                l++;
                continue;
            }

            if(inp[r]==cur)
            {
                score++;
                r--;
                continue;
            }

            score=-1;
            break;
        }

        if(score!=-1)
        {
            if(outp==-1)outp=score;
            else outp=min(outp,score);
        }
    }

    return outp;
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

        cout<<solve()<<"\n";
    }

    return 0;
}