#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;

int n,q;

char inp[nmax];

set<int> active;

void update(int pos,char c)
{
    inp[pos]=c;

    for(int i=pos-2;i<=pos;i++)
        if(1<=i&&i+2<=n)
        {
            active.erase(i);

            if(inp[i]=='a'&&inp[i+1]=='b'&&inp[i+2]=='c')active.insert(i);
        }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    cin>>n>>q;

    for(int i=1;i<=n;i++)cin>>inp[i];

    for(int i=1;i<=n;i++)update(i,inp[i]);

    for(int i=1;i<=q;i++)
    {
        int pos;
        char c;

        cin>>pos>>c;

        update(pos,c);

        cout<<active.size()<<"\n";
    }

    return 0;
}