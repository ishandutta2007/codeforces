#include <cstdio>
#include <iostream>
using namespace std;

int a[32];
int b[32];
int n,v;

int main(){
    int i,t=0;
    scanf("%d %d",&n,&v);
    for(i=0;i<n;++i){
        scanf("%d",a+i);
        t+=a[i];
    }//
    for(i=0;i<n;++i){
        scanf("%d",b+i);
    }
    double m=(double)b[0]/a[0];
    for(i=1;i<n;++i){
        double x=(double)b[i]/a[i];
        if(x<m)m=x;
    }
    printf("%lf\n",min(m*t,(double)v));
    return 0;
}