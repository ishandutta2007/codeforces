#include <iostream>
#include <algorithm>
using namespace std;
struct ura
{
    int a,b,p;
}v[300005];
bool cmp (ura a, ura b)
{
    if(a.a<b.a)
        return true;
    if(a.a>b.a)
        return false;
    if(a.b>b.b)
        return true;
    return false;
}
int main()
{
    long long n,i;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>v[i].a>>v[i].b;
        v[i].p=i;
    }
    sort(v+1,v+n+1,cmp);
    for(i=2;i<=n;i++)
    {
        if(v[i].b<=v[i-1].b)
        {
            cout<<v[i].p<<' '<<v[i-1].p;
            return 0;
        }
    }
    cout<<-1<<' '<<-1;
    return 0;
}