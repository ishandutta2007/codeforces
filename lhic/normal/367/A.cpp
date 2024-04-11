#include <iostream>
#include <string>
#include <cmath>
using namespace std;

struct str
{
    int x;
    int y;
    int z;
};


string s;

str t[400000];

str check(int a)
{
    str res;
    res.x=0;
    res.y=0;
    res.z=0;
    if (s[a]=='x')
    {
        res.x++;
    }
    else if (s[a]=='y')
    {
        res.y++;
    }
    else if (s[a]=='z')
    {
        res.z++;
    }
    return res;
}


str merge(str a,str b)
{
    str res;
    res.x=a.x+b.x;
    res.y=a.y+b.y;
    res.z=a.z+b.z;
    return res;
}

void build(int v,int l,int r)
{
    if (l==r)
    {
        t[v]=check(l);
        return;
    }
    int mid=(l+r)/2;
    build(v*2,l,mid);
    build(v*2+1,mid+1,r);
    t[v]=merge(t[2*v],t[2*v+1]);
}


str getAns(int v,int tl,int tr,int l,int r)
{
    str res;
    if (l>r)
    {
        res.x=0;
        res.y=0;
        res.z=0;
        return res;
    }
    if (tl==l && tr==r)
    {
        return t[v];
    }
    int mid=(tl+tr)/2;
    return merge(getAns(v*2,tl,mid,l,min(mid,r)) , getAns(v*2+1,mid+1,tr,max(mid+1,l),r));
}


bool checkReal(int l,int r)
{
    str now=getAns(1,0,s.size()-1,l,r);
    int delta=max(abs(now.x-now.y),max(abs(now.z-now.y),abs(now.z-now.x)));
    if (delta<=1 || now.x+now.y+now.z<3)
    {
        return true;
    }
    else
    {
        return false;
    }
}


int main()
{
    cin>>s;
    build(1,0,s.size()-1);
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        if (checkReal(a,b))
        {
            cout<<"YES\n";
        }
        else
        {
            cout<<"NO\n";
        }
    }
    return 0;
}