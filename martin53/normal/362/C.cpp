#include<bits/stdc++.h>
using namespace std;
const int nmax=5e3+42;
int n,arr[nmax];
int bigger[nmax][nmax];
int se(int l,int r,int p)
{
    return bigger[r+1][p]-bigger[l][p];
}
int fi(int p,int l,int r)
{
    if(l>r)return 0;
    return (r-l+1)-se(l,r,p);
}
int main()
{
scanf("%i",&n);
for(int i=1;i<=n;i++){scanf("%i",&arr[i]);arr[i]++;}
for(int index=1;index<=n+1;index++)
{
    for(int now=1;now<=n;now++)
    {
        bigger[index][now]=bigger[index-1][now];
        if(arr[index-1]>now)bigger[index][now]++;
        //cout<<index<<" "<<now<<" -> "<<bigger[index][now]<<endl;
    }
}
int swaps=n*(n+1)+1,times=0;
int sum=0;
for(int i=1;i<=n;i++)sum=sum+bigger[i][arr[i]];
for(int i=1;i<=n;i++)
    for(int j=i+1;j<=n;j++)
    {
        int now=sum;
        now=now-fi(arr[i],i+1,j-1);
        now=now-(arr[i]>arr[j]);
        now=now-se(i+1,j-1,arr[j]);
        //cout<<"Remove: "<<i<<" "<<j<<" => "<<now<<endl;

        now=now+fi(arr[j],i+1,j-1);
        now=now+(arr[j]>arr[i]);
        now=now+se(i+1,j-1,arr[i]);
        //cout<<"Add: "<<i<<" "<<j<<" => "<<now<<endl;
        if(now<swaps)
        {
            swaps=now;
            times=0;
        }
        if(now==swaps)times++;
    }
printf("%i %i\n",swaps,times);
return 0;
}