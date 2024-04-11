#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;

int n,inp[nmax];

vector<int> seen_x,seen_y;

bool cmp(int a,int b)
{
    return abs(a)<abs(b);
}

double dist(long long a,long long b)
{
    return sqrt(a*a+b*b);
}
void solve()
{
    seen_x={};
    seen_y={};

    scanf("%i",&n);
    for(int i=1;i<=2*n;i++)
    {
        //scanf("%i",&inp[i]);
        int x,y;

        scanf("%i%i",&x,&y);

        if(x)seen_x.push_back(x);
        else seen_y.push_back(y);
    }

    sort(seen_x.begin(),seen_x.end(),cmp);
    sort(seen_y.begin(),seen_y.end(),cmp);


    double outp=0;
    for(int i=0;i<n;i++)
        outp+=dist(seen_x[i],seen_y[i]);

    printf("%.18f\n",outp);
}

int main()
{
    int t;
    scanf("%i",&t);

    while(t)
    {
        t--;
        solve();
    }

    return 0;
}