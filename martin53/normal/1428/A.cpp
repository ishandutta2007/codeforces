#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;

int n,inp[nmax];

void solve()
{
    int x1,y1,x2,y2;
    scanf("%i%i%i%i",&x1,&y1,&x2,&y2);

    int diff_1=abs(x1-x2),diff_2=abs(y1-y2);

    int outp=0;

    if(diff_1==0||diff_2==0)outp=diff_1+diff_2;
    else outp=outp+diff_1+diff_2+2;

    printf("%i\n",outp);
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