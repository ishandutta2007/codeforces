#include<bits/stdc++.h>
using namespace std;
/*
const int lim=1e2;
int a[lim][lim];
int bits(long long x)
{
    if(x==0)return 0;
    return bits(x/2)+x%2;
}
void gen(int m)
{
for(int j=1;j<=m;j++)
	a[1][j]=0;
a[1][m+1]=1;

for(int i=2;i<=m+1;i++)
	for(int j=1;j<=m+1;j++)
	if(j==1)
		a[i][j]=a[i-1][j+1];
	else
	{
		if(j==m+1)a[i][j]=a[i-1][j-1];
		else a[i][j]=a[i-1][j-1]^a[i-1][j+1];
	}
int s=0;
for(int j=1;j<=m+1;j++)
    s=s+a[m+1][j];
cout<<m<<" -> "<<s<<" "<<bits(m+1)<<endl;
}
void brute()
{
for(int i=1;i<lim-1;i++)
    gen(i);
}
*/
map< pair< long long,int>, long long> mem;
long long rec(long long lim,int bits)//up to lim with bits one bits
{
    //cout<<lim<<" "<<bits<<endl;
    if(bits==0)return 1;
    if(lim==0)return 0;
    if(mem.count({lim,bits}))return mem[{lim,bits}];
    long long s=0;
    //bit is 0
    s=s+rec(lim/2,bits);
    //bit is 1
    s=s+rec((lim-1)/2,bits-1);
    mem[{lim,bits}]=s;
    //cout<<lim<<" "<<bits<<" -> "<<s<<endl;
    return s;
}
int main()
{
//brute();
long long n,t;
cin>>n>>t;
if((t&(t-1))!=0)
{
cout<<0<<endl;
return 0;
}
int b=0;
while(t)
{
    b++;
    t=t/2;
}
cout<<rec(n+1,b)-(b==1)<<endl;
return 0;
}