#include<bits/stdc++.h>
using namespace std;
const int N=1005,inf=0x3f3f3f3f;
int n;
int c[N],b[N];

string s;
int mincost=inf,mina=inf,minb=inf,minab=inf;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) 
    {
        cin>>c[i]>>s;
        for(int j=0;j<s.size();j++) b[i]+=(1<<(s[j]-'A'));
        if(b[i]==7) mincost=min(mincost,c[i]);
    }
    for(int i=1;i<=n;i++) 
    {
        if(b[i]&1) mina=min(mina,c[i]);
        if(b[i]&2) minb=min(minb,c[i]);
        if(b[i]==3) minab=min(minab,c[i]);
    }
    if(mina==inf||minb==inf) {puts("-1");return 0;}
    minab=min(minab,mina+minb);
    for(int i=1;i<=n;i++)
        if(b[i]&4)
        {
            if(b[i]==4) mincost=min(mincost,c[i]+minab);
            if(b[i]==5) mincost=min(mincost,c[i]+minb);
            if(b[i]==6) mincost=min(mincost,c[i]+mina);
        }
    if(mincost==inf) puts("-1");
    else cout<<mincost;
    return 0;
}