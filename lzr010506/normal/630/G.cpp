    #include<stdio.h>  
    #include<string.h>  
    #include<string>  
    #include<math.h>  
    #include<iostream>  
    #include<map>  
    #include<algorithm>  
    using namespace std;  
    #define LL __int64  
    LL C(LL m,LL n)  
    {  
        if(n>m)  
            return 0;  
        LL ans=1;  
        for(LL i=1;i<=n;i++)  
        {  
            ans*=m+1-i;  
            ans/=i;  
        }  
        return ans;  
    }  
    int main()  
    {  
        LL n;  
        while(scanf("%I64d",&n)!=EOF)  
        {  
            LL sum=C(n+4,5)*C(n+2,3);  
            printf("%I64d\n",sum);  
        }  
        return 0;  
    }