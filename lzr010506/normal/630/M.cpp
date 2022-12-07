    #include<stdio.h>  
    #include<string.h>  
    #include<string>  
    #include<iostream>  
    #include<algorithm>  
    using namespace std;  
    #define LL __int64  
    int main()  
    {  
        LL n;  
        while(scanf("%I64d",&n)!=EOF)  
        {  
            n=(n%360+360)%360;  
            if(n>=315)  
                printf("0\n");  
            else  
                printf("%I64d\n",n/90+(n%90-1)/45);  
      
        }  
        return 0;  
    }