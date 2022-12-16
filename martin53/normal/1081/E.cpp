#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+42;
int n;
int arr[nmax];
vector<int> possible[nmax];
vector<bool> been[nmax];
long long output[nmax];
void go(int pos,int index)
{
    if(pos==n)
    {
        printf("Yes\n");
        for(int j=0;j<n;j++)
            printf("%lld ",output[j]);
        exit(0);
    }
    if(been[pos][index])return;
    been[pos][index]=1;
    if(pos%2==1)
    {
        output[pos]=arr[pos/2+1];
        go(pos+1,index);
        return;
    }

    for(int j=0;j<possible[pos+1].size();j++)
    {
        int k=possible[pos+1][j];
        if(possible[pos][index]<k)
        {
            output[pos]=1LL*k*k-1LL*possible[pos][index]*possible[pos][index];
            go(pos+1,j);
        }
    }
}
int main()
{
scanf("%i",&n);
for(int i=1;i<=n/2;i++)scanf("%i",&arr[i]);

for(int i=1;i<=n/2;i++)
{
    int x,a,b;
    for(int d=1;d*d<=arr[i];d++)
        if(arr[i]%d==0)
        {
            x=arr[i]/d;
            b=d+x;
            if(b%2==1)continue;
            b=b/2;
            a=b-d;
            possible[2*i-1].push_back(a);
            possible[2*i].push_back(b);
            been[2*i-1].push_back(0);
            been[2*i].push_back(0);
        }
    if(possible[2*i-1].size()==0)
    {
        printf("No\n");
        return 0;
    }
}
possible[0].push_back(0);
been[0].push_back(0);
go(0,0);

printf("No\n");
return 0;
}