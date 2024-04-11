#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{  long long int k;
   long int i,n,j,x;
   cin>>n; k=0;
   long long int a[21];
   for (i=0;i<21;i++) a[i]=0;
   for (i=0;i<n;i++)  {cin>>x; a[x+10]++;}
   k=(a[10]*(a[10]-1))/2;
   for (i=0;i<10; i++)
    k+=a[i]*a[20-i];
   cout<<k;   
}