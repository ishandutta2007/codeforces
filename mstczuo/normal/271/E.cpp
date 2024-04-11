# include <iostream>
# include <cstdio>
using namespace std;

int n,m;
long long ans;
int gcd(int a,int  b)
{
    for(int t;b;t=a,a=b,b=t%a);
    return a;
}

void Sol(int k)
{
    while(k<m)
    {
        ans+=m-k;
        k=k<<1;
    }
}

int main()
{
    scanf("%d%d",&n,&m);
    int t=0,x;
    while(n--){
        scanf("%d",&x);
        t=gcd(x-1,t);
    }
    while(~t&1)t=t>>1;    

    for(n=1;n*n<t;n++)
        if(t%n==0)
            Sol(n),
            Sol(t/n);

    if(n*n==t)
        Sol(n);
    cout << ans << endl;
}