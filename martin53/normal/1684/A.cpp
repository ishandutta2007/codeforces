#include<bits/stdc++.h>
using namespace std;

char solve()
{
    string inp;

    cin>>inp;

    if(inp.size()==2)return inp[1];

    char mini='9';

    for(auto w:inp)
        mini=min(w,mini);

    return mini;
}

int main()
{
    int t;
    scanf("%i",&t);

    while(t)
    {
        t--;

        printf("%c\n",solve());
    }

    return 0;
}