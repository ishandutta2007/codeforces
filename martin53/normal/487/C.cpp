#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+42;
/*
const int nmax=15;
int n,a[nmax];
bool seen[nmax];
*/
bool prime(int n)
{
for(int i=2;i*i<=n;i++)
    if(n%i==0)return 0;
return 1;
}
int n;
int mem[nmax];
void solve(int a,int &x,int result)//a*x=result(mod n)
{
    //cout<<" solving "<<a<<" "<<result<<endl;
    int b=n;
    int x1=1,x2=0;
    int y1=0,y2=1;
    int q,r,x3,y3;
    while(b)
    {
        q=a/b,r=a%b;
        x3=x1-q*x2;
        y3=y1-q*y2;
        a=b;
        b=r;
        x1=x2;
        y1=y2;
        x2=x3;
        y2=y3;
    }
    //cout<<x1<<" "<<y1<<endl;
    long long ans=x1;
    ans=ans*result;
    ans=ans%n;
    if(ans<0)ans=ans+n;
    x=ans;
    //cout<<"result is "<<x<<endl;
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie();
cout.tie();
cin>>n;
/*
for(int i=1;i<=n;i++)a[i]=i;
int good=0,all=0;
do
{
    memset(seen,0,sizeof(seen));
    int value=1;
    bool ok=1;
    for(int i=1;i<=n;i++)
    {
    value=value*a[i]%n;
    if(seen[value]){ok=0;break;}
    seen[value]=1;
    }
    if(ok)
    {
        good++;
        for(int j=1;j<=n;j++)cout<<a[j]<<" ";cout<<endl;
    }
    all++;
}
while(next_permutation(a+1,a+n+1));
*/
if(n==1)
{
cout<<"YES"<<endl;
cout<<1<<endl;
return 0;
}
if(n==4)
{
cout<<"YES"<<endl;
cout<<1<<endl;
cout<<3<<endl;
cout<<2<<endl;
cout<<4<<endl;
return 0;
}
if(n==2)
{
cout<<"YES"<<endl;
cout<<1<<endl;
cout<<2<<endl;
return 0;
}

if(prime(n)==0)
{
cout<<"NO"<<endl;
return 0;
}

cout<<"YES"<<endl;
int d=n/2;
cout<<1<<endl;

for(int now=2;now<=d;now++)
{
    int prev=now-1,x;
    solve(prev,x,now);
    cout<<x<<endl;
    //find x, such that prev*x=now(mod n)
    solve(x,x,1);
    mem[n+1-now]=x;
}
cout<<n-1<<endl;
for(int now=d+2;now<n;now++)cout<<mem[now]<<endl;
cout<<n<<endl;
return 0;
}