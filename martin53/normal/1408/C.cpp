#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;

int n,inp[nmax];

int l;

void solve()
{
    scanf("%i%i",&n,&l);

    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    double outp=0;

    double t=0,x1=0,x2=l;

    int pointer_l=0,pointer_r=n+1;

    inp[0]=0;
    inp[n+1]=l;

    while(pointer_l<pointer_r)
    {
        int speed_1=pointer_l+1,speed_2=(n+2-pointer_r);

        double t1=1.0*(inp[pointer_l+1]-x1)/speed_1;
        double t2=1.0*(x2-inp[pointer_r-1])/speed_2;

        if(t1<t2)
        {
            outp+=t1;
            pointer_l++;
        }
        else
        {
            outp+=t2;
            pointer_r--;
        }

        x1=x1+min(t1,t2)*speed_1;
        x2=x2-min(t1,t2)*speed_2;

        //cout<<x1<<" "<<x2<<" "<<pointer_l<<" "<<pointer_r<<" "<<speed_1<<" "<<speed_2<<endl;
    }

    outp+=(x2-x1)/(n+2);

    printf("%.9f\n",outp);
}

int main()
{
    int t;

    scanf("%i",&t);

    while(t)
    {
        solve();
        t--;
    }
    return 0;
}