#include<bits/stdc++.h>
using namespace std;
int main()
{
int n,m;
scanf("%i%i",&n,&m);
if(n>m)swap(n,m);
if(n==1)printf("%i\n",m);
else if(n==2)printf("%i\n",m/4*4+min(4,m%4*2));
else printf("%i\n",(n*m+1)/2);
return 0;
}