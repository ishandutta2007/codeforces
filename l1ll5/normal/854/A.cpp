#include <cmath>
#include <queue>
#include <cstdio>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 100010
#define ll long long
using namespace std;
inline int read() 
{ 
    int x=0,f=1;char ch=getchar(); 
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();} 
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();} 
    return x*f; 
}
int gcd(int a,int b)
{return b==0?a:gcd(b,a%b);}
int n; 
int main()
{
	n=read();
	int l=n/2,r=n-l;
	while(gcd(l,r)!=1)
	{
		if((double)((l-1)/(r+1))>(double)((l+1)/(r-1)))
		l--,r++;
		else l++,r--;
	}
	if(r<l)swap(l,r);
	cout<<l<<' '<<r<<endl;
}