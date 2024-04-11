#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+42;
int n,k,h;
struct lem
{
int ind,m,v;
};
bool cmp(lem a,lem b)
{
    if(a.m!=b.m)return a.m<b.m;
    return a.v<b.v;
}
lem inp[nmax];
int now[nmax];
int outp[nmax];
int take(int ind,double m)
{
        long long p=m*inp[ind].v/h;
        p=min(p,1LL*k);
        return p;
}
bool test(double m)
{
    /*
    pq=emp;
    for(int i=1;i<=n;i++)
    {
        long long j=m*inp[i].v/h;
        j=min(j,1LL*k);
        pq.push({j,{inp[i].m,i}});
        //cout<<m<<" -> "<<i<<" "<<j<<endl;
    }
    */

    int w_max=0;

    int j=1;
    for(int i=1;i<=k;i++)
    {
        bool ok=0;

        while(j<=n&&take(j,m)<i)j++;

        //cout<<m<<" "<<i<<" "<<j<<" "<<w_max<<endl;

        while(j<=n)
        {
            if(inp[j].m>=w_max)
            {
                now[i]=inp[j].ind;
                w_max=inp[j].m;
                ok=1;
                j++;
                break;
            }
            j++;
        }
        if(ok==0)return 0;

    }

    for(int i=1;i<=k;i++)
        outp[i]=now[i];
    return 1;
}
int main()
{
scanf("%i%i%i",&n,&k,&h);
for(int i=1;i<=n;i++)
{
    scanf("%i",&inp[i].m);
}
for(int i=1;i<=n;i++)
{
    scanf("%i",&inp[i].v);
    inp[i].ind=i;
}

sort(inp+1,inp+n+1,cmp);

//for(int i=1;i<=n;i++)cout<<inp[i].ind<<" "<<inp[i].v<<" "<<inp[i].m<<endl;

double ok=(k*h+1),not_ok=0;
for(int i=0;i<90;i++)
{
    double av=(ok+not_ok)/2;
    if(test(av))ok=av;
    else not_ok=av;
}

//cout<<ok<<endl;

for(int i=1;i<=k;i++)
    printf("%i ",outp[i]);printf("\n");
return 0;
}