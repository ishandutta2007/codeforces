#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
struct ura
{
    char c[105];
    int dist;
}v[105];
bool cmp (ura a, ura b)
{
    if(a.dist<b.dist)
        return true;
    return false;
}
int main()
{
    int n,i,ok=1;
    cin>>n>>ws;
    for(i=1;i<=n;++i)
    {
        cin.getline(v[i].c,105);
        v[i].dist=strlen(v[i].c);
    }
    sort(v+1,v+n+1,cmp);
    for(i=1;i<n;++i)
    {
        if(strstr(v[i+1].c,v[i].c)==0)
        {
            ok=0;
            break;
        }
    }
    if(ok==0)
        cout<<"NO";
    else
    {
        cout<<"YES"<<'\n';
        for(i=1;i<=n;++i)
        {
            cout<<v[i].c<<'\n';
        }
    }
    return 0;
}