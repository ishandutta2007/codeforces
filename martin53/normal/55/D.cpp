#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+42,LIM=/*2521*//*10000*/2530;
long long mem[20][LIM][50][2];
int ind[LIM];
int g[LIM][10];
int arr[25],SZ=0;

long long mult[25];
long long rec(int pos,int mod,int product,bool done)
{
    //system("pause");
    if(pos==0)return (mod%product==0);
    if(mem[pos][mod][ind[product]][done]!=-1)
    {
    return mem[pos][mod][ind[product]][done];
    }
        long long ret=0;
    if(done==1)
    {
    for(int i=0;i<10;i++)
        ret=ret+rec(pos-1,(mod+i*mult[pos])%2520,/*product*(i==0?1:i/__gcd(i,product))*/g[product][i],1);
    }
    else//done=0
    {
        for(int i=0;i<=arr[pos];i++)
            ret=ret+rec(pos-1,(mod+i*mult[pos])%2520,/*product*(i==0?1:i/__gcd(i,product))*/g[product][i],i!=arr[pos]);
    }

    mem[pos][mod][ind[product]][done]=ret;
    //cout<<pos<<" "<<mod<<" "<<product<<" "<<done<<" -> "<<ret<<endl;
    return ret;
}

long long ask(long long num)
{
    SZ=0;
    while(num)
    {
        arr[++SZ]=num%10;
        num=num/10;
    }
    //reverse(arr+1,arr+SZ+1);
    memset(mem,-1,sizeof(mem));
    return rec(SZ,0,1,0);
}
int main()
{
int id=0;
for(int i=1;i<LIM;i++)
    if(__gcd(i,8)*__gcd(i,9)*__gcd(i,5)*__gcd(i,7)==i)
    {
        id++;
        ind[i]=id;
    }

mult[1]=1;
for(int i=2;i<20;i++)mult[i]=10*mult[i-1]%2520;

for(int i=1;i<LIM;i++)
    for(int j=0;j<10;j++)
        if(j==0)g[i][j]=i;
        else g[i][j]=i*j/__gcd(i,j);
int q;
cin>>q;
long long l,r;
for(int i=1;i<=q;i++)
{
    cin>>l>>r;

    cout<<ask(r)-ask(l-1)<<endl;
}
return 0;
}