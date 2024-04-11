#include <bits/stdc++.h>

using namespace std;
int aib[200005];
int ocup[200005];
struct ura
{
    int av,bv,a,b;
}v[200005];
bool cmp1 (ura a, ura b)
{
    return a.av<b.av;
}
bool cmp2 (ura a, ura b)
{
    return a.bv<b.bv;
}
bool cmp3 (ura a, ura b)
{
    if(a.a>b.a)
        return true;
    if(a.a<b.a)
        return false;
    return a.b<b.b;
}
int lsb (int x)
{
    return x&-x;
}
void baga (int pz)
{
    for(int i=pz;i<=200000;i+=lsb(i))
        ++aib[i];
}
int cat (int pz)
{
    long long s=0;
    for(int i=pz;i>0;i-=lsb(i))
        s+=aib[i];
    return s;
}
int main()
{
    long long n,m,i,j,a,b,c,cnt=0,k,s=0;
    cin>>n;
    n%=4;
    if(n%4==1)
    {
        cout<<0<<" A";
    }
    else
    if(n%4==0)
    {
        cout<<1<<" A";
    }
    else
    if(n%4==3)
    {
        cout<<2<<" A";
    }
    else
        cout<<1<<" B";
    return 0;
}