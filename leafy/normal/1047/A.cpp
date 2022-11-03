#include <iostream>
#include <cstdio>
using namespace std;
int n;
int main()
{
    cin>>n;
    if(n%3!=2){printf("1 1 %d",n-2);return 0;}
    else if(n%3!=0) {printf("1 2 %d",n-3);return 0;}
    else printf("2 2 %d",n-4);
    return 0;
}