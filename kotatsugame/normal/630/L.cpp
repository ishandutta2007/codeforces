#include<iostream>
#include<cstdio>
using namespace std;
main()
{
	int N_;
	cin>>N_;
	int N=N_/10000*10000+N_/100%10*1000+N_%10*100+N_/10%10*10+N_/1000%10;
	long long E=1;
	for(int i=0;i<5;i++)E=E*N%100000;
	printf("%05d\n",E);
}