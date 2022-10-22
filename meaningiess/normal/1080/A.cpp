#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
	int n,k;
	cin>>n>>k;
	int a=ceil(2.0*n/k),b=ceil(5.0*n/k),c=ceil(8.0*n/k);
	cout<<(int)(a+b+c);
}