#include<bits/stdc++.h>
using namespace std;

const int nmax=3e5+42;

int n;
string inp;

int main()
{
    cin>>n;

    cin>>inp;

    int sum=0;
    for(auto k:inp)
        if(k=='(')sum++;
        else sum--;

    if(sum)
    {
        cout<<0<<endl;
        cout<<1<<" "<<1<<endl;
        return 0;
    }

    int outp=0,l_best=0,r_best=0;

    for(int l=0;l<n;l++)
        for(int r=l;r<n;r++)
        {
            swap(inp[l],inp[r]);

            int cur_sum=0,least=1e9,cnt=0;

            for(auto k:inp)
            {
                if(k=='(')cur_sum++;
                else cur_sum--;

                if(cur_sum<least)
                {
                    least=cur_sum;
                    cnt=0;
                }

                if(cur_sum==least)cnt++;
            }

            if(outp<cnt)
            {
                outp=cnt;
                l_best=l;
                r_best=r;
            }

            swap(inp[l],inp[r]);
        }

    cout<<outp<<endl<<l_best+1<<" "<<r_best+1<<endl;
    return 0;
}