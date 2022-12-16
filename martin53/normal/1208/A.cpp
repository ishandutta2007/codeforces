#include<bits/stdc++.h>
using namespace std;
const int nmax=1e6+42;
int t;
int main()
{
    scanf("%i",&t);
    for(int i=1;i<=t;i++)
    {
        int a,b,n;
        scanf("%i%i%i",&a,&b,&n);
        int arr[3]={a,b,a^b};
        printf("%i\n",arr[n%3]);
    }



}