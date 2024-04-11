#include<bits/stdc++.h>
using namespace std;
const int nmax=1e6+42;
string inp;
int main()
{
    cin>>inp;
    int n=inp.size();

    for(int mid=0;mid<=n;mid++)
    {
    int open=0,close=0;
        for(int i=0;i<mid;i++)
            if(inp[i]=='(')open++;
        for(int i=mid;i<n;i++)
            if(inp[i]==')')close++;

        if(open==close&&open)
        {
            printf("1\n");
            printf("%i\n",open+close);
            for(int i=0;i<mid;i++)
                if(inp[i]=='(')printf("%i ",i+1);
            for(int i=mid;i<n;i++)
                if(inp[i]==')')printf("%i ",i+1);
            return 0;
        }

    }
    printf("0\n");
    return 0;
}