#include <bits/stdc++.h>
using namespace std;
vector<int>v;
void increase (int &a, int &b, int h, int m)
{
    ++b;
    if(b==m)
    {
        b=0;
        ++a;
        if(a==h)
            a=0;
    }
}
int get (int a)
{
    if(a==0)
        return 0;
    if(a==1)
        return 1;
    if(a==8)
        return 8;
    if(a==2)
        return 5;
    if(a==5)
        return 2;
    return -1;
}
bool verif (int a, int b, int h, int m)
{
    int ca,cb;
    ca=get(b%10);
    if(ca==-1)
        return false;
    int x=get(b/10);
    if(x==-1)
        return false;
    ca=ca*10+x;
    cb=get(a%10);
    if(cb==-1)
        return false;
    x=get(a/10);
    if(x==-1)
        return false;
    cb=cb*10+x;
    if(ca<h && cb<m)
        return true;
    return false;
}
void afis (int a)
{
    if(a<10)
        cout<<0<<a;
    else
        cout<<a;
}
int main ()
{
    ios_base::sync_with_stdio(0);
    int t,m,i,j,k=0,s=0,mn,mx=0;
    cin>>t;
    while(t--)
    {
        int h;
        cin>>h>>m;
        char c;
        int a,b;
        cin>>c;
        a=c-'0';
        cin>>c;
        a=a*10+(c-'0');
        cin>>c>>c;
        b=c-'0';
        cin>>c;
        b=b*10+(c-'0');
        while(!verif(a,b,h,m))
        {
            increase(a,b,h,m);
        }
        afis(a);
        cout<<':';
        afis(b);
        cout<<'\n';
    }
}