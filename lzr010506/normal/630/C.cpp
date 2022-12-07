    #include<stdio.h>  
    #include<string.h>  
    #include<math.h>  
    using namespace std;  
      
    int main()  
    {  
        int t;  
        scanf("%d",&t);  
        long long sum = 1;  
        for(int i=1;i<=t+1;i++)  
        {  
            sum = sum * 2;  
        }  
        printf("%I64d",sum-2);  
    }