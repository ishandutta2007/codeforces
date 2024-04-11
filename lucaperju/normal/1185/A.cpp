#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a>b)
        swap(a,b);
    if(b>c)
        swap(b,c);
    if(a>b)
        swap(a,b);
    if(b>c)
        swap(b,c);
    if(a>b)
        swap(a,b);
    if(b>c)
        swap(b,c);
    if(a>b)
        swap(a,b);
    if(b>c)
        swap(b,c);
    cout<<max(0LL,a-(b-d))+max(0LL,(b+d)-c);
    return 0;
}