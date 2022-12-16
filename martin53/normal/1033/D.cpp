#include<bits/stdc++.h>
using namespace std;
const int mod=998244353,nmax=5e2+42;

long long my_mult(long long a,long long b,long long c)
{
if(b==0)return 0;
long long v=my_mult(a,b/2,c);
if(b%2==0)return (v+v)%c;
return (v+v+a)%c;
}
long long my_pow(long long a,long long b,long long c)
{
if(b==0)return 1;
long long v=my_pow(a,b/2,c);
if(b%2==0)return my_mult(v,v,c);
return my_mult(my_mult(v,v,c),a,c);
}
vector<int> pr={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
bool prime(long long n)
{
if(n==1)return 0;
if(n==2)return 1;
if(n%2==0)return 0;
long long r=0,d=n-1;
while(d%2==0)
{
d=d/2;
r++;
}
//cout<<r<<" "<<d<<endl;
for(auto k:pr)
{
if(k>n-2)continue;
long long x=my_pow(k,d,n);
if(x==1||x==n-1)continue;
bool stopped=0;
    for(int j=1;j<=r-1;j++)
    {
    x=my_pow(x,2,n);
    if(x==1)return 0;
        if(x==n-1)
        {
        stopped=1;
        break;
        }
    }
    if(stopped==0)return 0;
}
return 1;
}

map<long long,int> seen;
long long arr[nmax];
int ind=0;
void run()
{
    long long a;
    scanf("%lld",&a);
    long long c=sqrt(a);
    while((c+1)*(c+1)<=a)c++;
    while((c-1)*(c-1)>a)c--;
    if(c*c==a&&prime(c))
    {
        seen[c]++;
        seen[c]++;
        return;
    }
    c=pow(a,1.0/3);
    while((c+1)*(c+1)*(c+1)<=a)c++;
    while((c-1)*(c-1)*(c-1)>a)c--;
    if(c*c*c==a&&prime(c))
    {
        seen[c]++;
        seen[c]++;
        seen[c]++;
        return;
    }
    c=pow(a,1.0/4);
    while((c+1)*(c+1)*(c+1)*(c+1)<=a)c++;
    while((c-1)*(c-1)*(c-1)*(c-1)>a)c--;
    if(c*c*c*c==a&&prime(c))
    {
        seen[c]++;
        seen[c]++;
        seen[c]++;
        seen[c]++;
        return;
    }


    arr[++ind]=a;
}
map<long long,int> other;
int main()
{
int t;
scanf("%i",&t);
for(int i=1;i<=t;i++)
    run();

for(int i=1;i<=ind;i++)
    for(auto &k:seen)
    while(arr[i]%k.first==0)
    {
        arr[i]=arr[i]/k.first;
        k.second++;
    }

for(int i=1;i<=ind;i++)
    for(int j=i+1;j<=ind;j++)
    {
        if(arr[i]==arr[j])continue;
        long long p=__gcd(arr[i],arr[j]);
        if(p==1)continue;
        for(int k=1;k<=ind;k++)
            if(arr[k]%p==0)
            {
                arr[k]=arr[k]/p;
                seen[p]++;
            }
    }

for(int i=1;i<=ind;i++)
    if(prime(arr[i]))
    {
        seen[arr[i]]++;
        arr[i]=1;
    }

for(int i=1;i<=ind;i++)
    if(arr[i]!=1)
        other[arr[i]]++;

long long ans=1;
for(auto k:seen)
    ans=ans*(k.second+1)%mod;

for(auto k:other)
    ans=ans*(k.second+1)*(k.second+1)%mod;
printf("%lld\n",ans);
return 0;
}