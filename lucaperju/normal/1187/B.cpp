#include <bits/stdc++.h>
using namespace std;
int cmmdc (int a, int b)
{
    int r;
    while(b)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
int fv[200005][30],fvc[30];
char v[200005];
bool verif (int pz)
{
    int i;
    for(i=0;i<=26;++i)
        if(fvc[i]>fv[pz][i])
            return false;
    return true;
}
int main ()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long n,m,ta,tb,i,j,nrc=0,nrd=0,s=0,t,a,b,c,rz=0,q,pz=-1,k1=0,k2=0,k=0,cnt=0,pas;
    cin>>n;
    char x;
    for(i=1;i<=n;++i)
    {
        cin>>x;
        ++fv[i][x-'a'];
        for(j=0;j<=26;++j)
            fv[i][j]+=fv[i-1][j];
    }
    cin>>m;
    for(i=1;i<=m;++i)
    {
        cin>>v;
        int nc=strlen(v);
        for(j=0;j<nc;++j)
            ++fvc[v[j]-'a'];
        k=0;
        pas=1<<18;
        while(pas)
        {
            if(k+pas<=n && !verif(k+pas))
                k+=pas;
            pas>>=1;
        }
        cout<<k+1<<'\n';
        for(j=0;j<nc;++j)
            --fvc[v[j]-'a'];
    }
    return 0;
}