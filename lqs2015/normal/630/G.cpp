#include<iostream>
#include<cstring>
using namespace std;
long long n,p,s,i;
long long que5()
{
	if (n==1) return 1;
	else if (n==2) return 6;
	else if (n==3) return 21;
	else if (n==4) return 56;
	else return n+n*(n-1)*2+n*(n-1)*(n-2)+n*(n-1)*(n-2)*(n-3)/6+n*(n-1)*(n-2)*(n-3)*(n-4)/120;
}
long long que3()
{
	if (n==1) return 1;
	else if (n==2) return 4;
	else return n+(n-1)*n+n*(n-1)*(n-2)/6; 
}
int main()
{
	cin>>n;
	p=que5();
	s=que3();
	cout<<p*s<<endl;
	return 0;
}