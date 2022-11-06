#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath> 
using namespace std;
int Abs(int x){return x>0?x:-x;}
int gcd(int a,int b){return b==0?a:gcd(b,a%b);}
int main()
{
	long long  n,m,a,b;scanf("%lld%lld%lld%lld",&n,&m,&a,&b);
	long long k=n%m;
	printf("%lld",min(k*b,(m-k)*a));return 0;
}