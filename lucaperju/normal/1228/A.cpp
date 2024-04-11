#include <bits/stdc++.h>

using namespace std;
bool verif (int val)
{
    int fv[10];
    for(int i=0;i<=9;++i)
        fv[i]=0;
    while(val)
    {
        ++fv[val%10];
        val/=10;
    }
    for(int i=0;i<=9;++i)
        if(fv[i]>=2)
            return 0;
    return 1;
}
int main()
{
    int l,r,i;
    cin>>l>>r;
    for(i=l;i<=r;++i)
    {
        if(verif(i))
        {
            cout<<i;
            return 0;
        }
    }
    cout<<-1;
    return 0;
}