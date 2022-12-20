#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+42;
int n,q;
int nxt[nmax];
int moves[nmax];

bool been[nmax];

int v[nmax],b[nmax];

int output;

pair<int/*where*/,int/*after how many turns*/> go(int start,int t)
{
    //cout<<"go "<<start<<" "<<t<<" "<<output<<endl;

    if(t==0)return {start,0};
    if(been[start])
    {
        if(moves[start]>t||nxt[start]==start)return {start,0};
        pair<int/*where*/,int/*after how many turns*/> current=go(nxt[start],t-moves[start]);
        current.second+=moves[start];
        return current;
    }

    been[start]=1;
    output++;

    pair<int/*where*/,int/*after how many turns*/> current=go(nxt[start],t-1);
    nxt[start]=current.first;
    moves[start]=current.second+1;

    //cout<<start<<" "<<nxt[start]<<" "<<moves[start]<<endl;
    return {nxt[start],moves[start]};
}
int main()
{
    scanf("%i%i",&n,&q);
    for(int i=1;i<=n;i++)
    {
        scanf("%i",&nxt[i]);
        moves[i]=1;
    }
    for(int i=1;i<=q;i++)scanf("%i",&v[i]);

    for(int i=1;i<=q;i++)scanf("%i",&b[i]);

    for(int i=1;i<=q;i++)
    {
        int start=((v[i]+output-1)%n)+1;

        output=0;
        go(start,b[i]);

        printf("%i\n",output);
    }
    return 0;
}