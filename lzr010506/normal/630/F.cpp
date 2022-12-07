    #include<bits/stdc++.h>  
    using namespace std;  
    long long C(int a,int b)                     //GET  
    {  
        long long ans=1;  
        for(int i=0;i<b;++i)  
        {  
            ans*=a-i;  
            ans/=i+1;  
        }  
        return ans;  
    }  
    int main()  
    {  
        int n;  
        while(cin>>n)  
        {  
            cout<<C(n,5)+C(n,6)+C(n,7)<<endl;  
        }  
    }