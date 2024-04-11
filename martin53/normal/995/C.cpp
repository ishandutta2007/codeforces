#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+42;
const double STOP=1.5e6;
int n;
pair<int,int> inp[nmax];
int order[nmax];
int output[nmax];
double eval()
{
    double x=0,y=0;
    for(int i=1;i<=n;i++)
    {
        double x_1=x+inp[order[i]].first,y_1=y+inp[order[i]].second;
        double x_2=x-inp[order[i]].first,y_2=y-inp[order[i]].second;
        if(x_1*x_1+y_1*y_1<x_2*x_2+y_2*y_2)
        {
            output[order[i]]=1;
            x=x_1;
            y=y_1;
        }
        else
        {
            output[order[i]]=-1;
            x=x_2;
            y=y_2;
        }
    }
    return sqrt(x*x+y*y);
}
int main()
{
mt19937 rng(time(0));
scanf("%i",&n);
for(int i=1;i<=n;i++)scanf("%i%i",&inp[i].first,&inp[i].second);
for(int i=1;i<=n;i++)order[i]=i;
while(1)
{
    double now=eval();
    if(now<STOP)break;
    shuffle(order+1,order+n+1,rng);
}
for(int j=1;j<=n;j++)printf("%i ",output[j]);
return 0;
}