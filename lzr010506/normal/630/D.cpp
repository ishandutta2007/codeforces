#include<stdio.h>  
#include<string.h>  
#include<math.h>  
using namespace std;  
      
int main()  
{  
    long long t;  
    scanf("%I64d",&t);  
    long long sum = 1;  
    long long n = 1;  
        
    n=(1+t)*t*3;  
    sum=sum+n;  
    if(t==0)printf("1");  
    else printf("%I64d",sum);  
}