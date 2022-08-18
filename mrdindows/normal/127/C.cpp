#include <iostream>
//#include <conio.h>
using namespace std;

long int mini(long int a,long int b) {
    if (a<b) return a; else return b;}

long int nod(long int a,long int b) {
  while ((a!=0)&&(b!=0)) {
       if (a>b) a%=b; else b%=a;

     
     }   
        if (a==0 && b==0) return(1); else return(a+b-mini(a,b));}   
     
     
     
     
int main ()
 {  long long int t1,t0,t2,x1,x2,y1,y2,i,j,c,v;
    long double k,p,min;
    cin>>t1>>t2>>x1>>x2>>t0;
    c=(t0-t1)/nod(t0-t1,t2-t0);
    v=(t2-t0)/nod(t0-t1,t2-t0);
    
    if ((c==0)||(v==0)) if (t1==t2) cout<<x1<<" "<<x2; else if (c==0) cout<<x1<<" "<<0; else cout<<0<<" "<<x2; else 
                                
    if ((c<=x2)&&(v<=x1))   
                    cout<<mini(x2/c,x1/v)*v<<" "<<mini(x2/c,x1/v)*c;  else{                                      
                                
                                
             
                                
    k=((long double)(t2-t0))/(t0-t1);

     min=t2-t0+1;y1=0;y2=1;
    if (k==1) cout<<mini(x1,x2)<<" "<<mini(x1,x2); else
    {
    for (i=1;i<x2+1;i++) {
       j=mini((long int)(i*k),x1);
      p=(t2*i+t1*j)/((long double)i+j);

      if (p-t0<=min) if ((p-t0<min)||(y1+y2<i+j)){min=p-t0; y1=j;y2=i;}
      
      }
      cout<<y1<<" "<<y2;
      
}
} 

    return 0;   
         }