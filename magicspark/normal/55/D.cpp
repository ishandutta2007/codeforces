 #include<cstdio> 
 #include<cstring> 
 #include <iostream>
 using namespace std;
 typedef long long ll; 
 int c[2555],n[20],g[2555][10],h[255][10]; 
 ll f[20][50][255],l,r; 
   
 int gcd(int x,int y){ 
     return y?gcd(y,x%y):x; 
 } 
   
 ll dfs(int l,int m,int r,bool z){ 
     if(l==-1)return !(r%m); 
     if(!z&&f[l][c[m]][r]!=-1) return f[l][c[m]][r]; 
     ll res=0; 
     int u=z?n[l]:9; 
     for(int d=0;d<=u;++d) 
         res+=dfs(l-1,g[m][d],l?h[r][d]:r*10+d,z&&d==u); 
     return z?res:f[l][c[m]][r]=res; 
 } 
   
 ll s(ll x){ 
     int l=0; 
     for (;x;x/=10)n[l++]=x%10; 
     return dfs(l-1,1,0,1); 
 } 
   
 int main(){ 
     memset(f,-1,sizeof f); 
     int i,j,t; 
     for(i=1,r=-1;i<=2520;++i) 
         c[i]=r+=!(2520%i); 
     for(j=0;j<10;++j){ 
         for(i=1;i<=2520;++i) 
             g[i][j]=j?i*j/gcd(i,j):i; 
         for(i=0;i<252;++i) 
             h[i][j]=(i*10+j)%252; 
     } 
     scanf("%d",&t);
     while(t--){ 
         scanf("%I64d%I64d",&l,&r); 
         printf("%I64d\n",s(r)-s(l-1)); 
     }
     //system("pause");
     return 0; 
 }