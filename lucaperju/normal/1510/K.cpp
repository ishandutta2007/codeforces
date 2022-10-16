#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
int v[2003],n;
void do1 ()
{
    for(int i=1;i+1<=2*n;i+=2)
    {
        swap(v[i],v[i+1]);
    }
}
void do2 ()
{
    for(int i=1;i+n<=2*n;++i)
        swap(v[i],v[i+n]);
}
bool check ()
{
    for(int i=1;i<=2*n;++i)
        if(v[i]<v[i-1])
            return false;
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    int t,d,i,j;
    int s=0;
    cin>>n;
    int cnt=0;
    for(i=1;i<=n+n;++i)
        cin>>v[i];
    if(n%2==0)
    {
        if(check())
        {
            cout<<0;
            return 0;
        }
        do1();
        if(check())
        {
            cout<<1;
            return 0;
        }
        do2();
        if(check())
        {
            cout<<2;
            return 0;
        }
        do2();
        do1();
        do2();
        if(check())
        {
            cout<<1;
            return 0;
        }
        cout<<-1;
        return 0;
    }
    else
    {
        for(i=1;i<=2*n;++i)
        {
            if(i%2)
            {
                do1();
            }
            else
                do2();
            if(check())
                break;
        }
        if(i==2*n+1)
            cout<<-1;
        else
            cout<<min(i,2*n-i);
    }
	return 0;
}