#include<bits/stdc++.h>
using namespace std;
const int nmax=18;
int n;
double a[nmax][nmax];
double ans[1<<nmax][nmax];
bool solved[1<<nmax];
void rec(int state/*1-> alive; 0-> dead*/)
{
    if(solved[state])return;
    int alive=0;
    for(int i=0;i<n;i++)
        if((state&(1<<i)))alive++;
    if(alive==1)
    {
        for(int i=0;i<n;i++)
            if((state&(1<<i)))
            {
            solved[state]=1;
            ans[state][i]=1;
            return;
            }
    }
    for(int i=0;i<n;i++)
        if((state&(1<<i)))
        {
            double sum=0;
            for(int j=0;j<n;j++)
                if((state&(1<<j))&&i!=j)sum=sum+a[j][i];
            rec(state-(1<<i));
            for(int j=0;j<n;j++)
                ans[state][j]=ans[state][j]+ans[state-(1<<i)][j]*sum/((alive-1)*alive/2);
        }
    solved[state]=1;
}
int main()
{
cin>>n;
for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
        cin>>a[i][j];
rec((1<<n)-1);
for(int i=0;i<n;i++)
    printf("%.18f ",ans[(1<<n)-1][i]);
printf("\n");
return 0;
}