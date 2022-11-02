#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int n,q,i;
int ar[N];
int ei,si,fo,tw;

bool check()
{
    if(ei>0)
        return true;
    if(si+fo+tw>=2 && si>=1)
        return true;
    if(fo>=1)
    {
        if(fo+tw>=3)
            return true;
        else if(fo>=2)
            return true;
        else
            return false;
    }
    return false;
}
int main()
{
    cin>>n;
    for(i=0;i<n;i++)
    {
        int a;
        cin>>a;
        ar[a]++;
        if(ar[a]==2)
            tw++;
        if(ar[a]==4)
            fo++,tw--;
        if(ar[a]==6)
            si++,fo--;
        if(ar[a]==8)
            ei++,si--;
    }
    cin>>q;
    while(q--)
    {
        char c;
        int a;
        cin>>c>>a;
        if(c=='+')
        {
            ar[a]++;
            if(ar[a]==2)
                tw++;
            if(ar[a]==4)
                fo++,tw--;
            if(ar[a]==6)
                si++,fo--;
            if(ar[a]==8)
                ei++,si--;
        }
        else
        {
            ar[a]--;
            if(ar[a]==1)
                tw--;
            if(ar[a]==3)
                fo--,tw++;
            if(ar[a]==5)
                si--,fo++;
            if(ar[a]==7)
                ei--,si++;
        }
        if(check())
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
}