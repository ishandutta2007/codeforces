#include <iostream>
//#include <conio.h>
using namespace std;
int main()
{
     long long n=0,s,k=1;
	 cin>>s;
	 for (int i=1;i<s;i++)
	 {
		 k=(k*3)%1000000007;
		 if (n>k)n-=1000000007;
		 n=k-n;
	 }
	 cout<<n;
//	 getch();
     return 0;
}