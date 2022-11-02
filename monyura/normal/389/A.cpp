#include <iostream>

using namespace std;

int gcd(int a, int b)
{
while(b)
{
int c = b;
b = a % b;
a = c;
}
return a;
}

int main()
{
int n;
cin>>n;
int a = 0;
for (int i = 0; i < n; i++)
{
int b;
scanf("%d",&b);
a = gcd(a,b);
}
cout<<a*n<<endl;
return 0;
}