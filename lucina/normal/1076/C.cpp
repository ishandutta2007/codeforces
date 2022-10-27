#include<bits/stdc++.h>
using namespace std;
int n,m,c,t,x;
double a,b,d;
int main(){
    scanf("%d",&t);
    for(int kk=1;kk<=t;kk++){
        scanf("%lf",&d);
        if(d*d<4.0*d){
            printf("N\n");
            continue;
            }
        a=(d-sqrt(d*d-4.0*d))/(2.0);
        b=d-a;
        printf("Y %.9f %.9f",b,a);
        printf("\n");
    }

}