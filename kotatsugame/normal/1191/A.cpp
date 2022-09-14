#include<iostream>
using namespace std;
char f(int N){return N%4==0?'D':N%4==2?'C':N%4==3?'B':'A';}
int X;
main()
{
    cin>>X;
    int a=0;
    char b=f(X);
    for(int i=1;i<=2;i++)
    {
        X++;
        char now=f(X);
        if(b>now)b=now,a=i;
    }
    printf("%d %c\n",a,b);
}