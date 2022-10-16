#include <bits/stdc++.h>

using namespace std;
int fv[200005];
struct ura
{
    char a,b;
}v[5];
bool cmp (ura a, ura b)
{
    if(a.a<b.a)
        return true;
    if(a.a>b.a)
        return false;
    return a.b<b.b;
}
int main()
{
    int n,m,i,j,c,cnt=0,k,s=0,mn=2;
    char a,b;
    cin>>b>>a;
    v[1].a=a;
    v[1].b=b;
    ++fv[a*200+(b-'0')];
    if(fv[a*200+(b-'0')]==2)
        mn=min(mn,1);
    else
        if(fv[a*200+(b-'0')]==3)
            mn=min(mn,0);
    cin>>b>>a;
    v[2].a=a;
    v[2].b=b;
    ++fv[a*200+(b-'0')];
    if(fv[a*200+(b-'0')]==2)
        mn=min(mn,1);
    else
        if(fv[a*200+(b-'0')]==3)
            mn=min(mn,0);
    cin>>b>>a;
    v[3].a=a;
    v[3].b=b;
    ++fv[a*200+(b-'0')];
    if(fv[a*200+(b-'0')]==2)
        mn=min(mn,1);
    else
        if(fv[a*200+(b-'0')]==3)
            mn=min(mn,0);
    sort(v+1,v+4,cmp);
    if(v[1].a == v[2].a && v[1].b== v[2].b-1 || v[2].a == v[3].a && v[2].b == v[3].b-1 || v[1].a == v[2].a && v[1].b== v[2].b-2 || v[2].a == v[3].a && v[2].b == v[3].b-2)
        mn=min(mn,1);
    if(v[1].a == v[2].a && v[1].b== v[2].b-1 && v[2].a == v[3].a && v[2].b == v[3].b-1)
        mn=min(mn,0);
    cout<<mn;
    return 0;
}