#include<iostream>
using namespace std;
int n,a;
int main()
{
	cin>>n>>a;
    if (n-a>a-1 && a+1<=n) cout<<a+1;
    else if (n-a<=a-1 && a-1>=1) cout<<a-1;
    else cout<<a;
	return 0;
}