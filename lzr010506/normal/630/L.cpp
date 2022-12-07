#include<stdio.h>  
#include<string.h>  
#include<string>  
#include<iostream>  
#include<algorithm>  
using namespace std;  
#define LL __int64  
string x;  
int main()  
{  
    LL n;  
    while(cin>>x)  
    {  
        n = (x[0] - '0') * 10000 + (x[1] - '0') + (x[2]-'0')*1000+(x[3]-'0')*10+(x[4]-'0')*100;  
        LL ans = 1;  
        for(LL i = 0; i < 5; i ++)  
            ans=ans * n % 100000;  
        printf("%05I64d\n",ans);  
    } 
    return 0;  
}