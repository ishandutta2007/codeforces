#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int q,i,j;
int n;
int pot[N];
double chance[N][110];
double new_chance[N][110];
double cur = 0;
int maxi[N];

double binom(int a, int b)
{
    double aa = 1, bb = 1;
    int ii=1;
    if(b==0)
        return 1;
    while(b--)
    {
        aa*=a; a--;
        bb*=ii; ii++;
    }
    if(aa<=0)
        return 0;
    else
        return aa/bb;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>pot[i];
        maxi[i] = pot[i];
        chance[i][pot[i]] = 1;
        if(pot[i]==0)
            cur++;
    }
    cin>>q;
    while(q--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        cur-=chance[a][0];
        for(i=0;i<=maxi[a];i++)
        {
            new_chance[a][i]+=binom(pot[a]-i,c)/ binom(pot[a],c)*chance[a][i];
            for(j=1;j<=c;j++)
            {
                new_chance[a][i]+=chance[a][i+j]*binom(i+j,j)*binom(pot[a]-i-j,c-j)/ binom(pot[a],c);
            }
        }
        for(i=0;i<=100;i++)
        {
            chance[a][i]=new_chance[a][i];
            new_chance[a][i] = 0;
        }
        if(chance[a][maxi[a]]==0)
            maxi[a]--;
        pot[a]-=c;
        pot[b]+=c;
        cur+=chance[a][0];
        cout.precision(15);
        cout<<cur<<"\n";
    }
}