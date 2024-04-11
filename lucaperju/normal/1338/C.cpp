#include <bits/stdc++.h>
using namespace std;
int ocp[100005];
int rz[100005];
void bin (int val)
{
    for(int i=1;i<=10;++i)
    {
        cout<<val%2;
        val/=2;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long n,i,j=0,t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        long long cn=n;
        long long nr1,nr2;
        long long nrgr=(n-1LL)/3LL+1LL;
        nr1=1;
        long long catcr=1;
        while(nrgr>catcr)
        {
            nrgr-=catcr;
            catcr*=4LL;
        }
        nr1=catcr+nrgr-1;
        nr2=catcr*2;
        long long powc=1;
        n=nrgr-1;
        while(n)
        {
            if(n%4==1)
                nr2+=powc*2LL;
            if(n%4==2)
                nr2+=powc*3LL;
            if(n%4==3)
                nr2+=powc;
            powc*=4LL;
            n/=4LL;
        }
        if(cn%3LL==1)
            cout<<nr1;
        else
        if(cn%3LL==2)
            cout<<nr2;
        else
            cout<<(nr1^nr2);
        cout<<'\n';
    }
        /* t=200;
         while(t--)
         {
             for(i=1;i<=100000;++i)
                 if(!ocp[i])
                     break;
             ocp[i]=1;
             rz[++j]=i;
             for(i=1;i<=100000;++i)
                 if(!ocp[i] && !ocp[i^rz[j]])
                     break;
             ocp[i]=ocp[i^rz[j]]=1;
             rz[++j]=i;
             rz[++j]=i^rz[j-2];
         }
         for(i=1;i<=200;++i)
         {
             if(i%3==1)
             {
                 cout<<i/3+1<<' ';
             }
             if(i%3)
             {
                 bin(rz[i]);
                 cout<<' ';
             }
             else
             {
                 bin(rz[i]);
                 cout<<'\n';
             }
         }*/
        return 0;
}