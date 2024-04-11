#include<bits/stdc++.h>
using namespace std;
int n,x,a,b;
bool fuck;

int main(){
    scanf("%d",&n);
    x=(int)sqrt(n);
    fuck=true;
    for(int i=x;i>=2;i--){
        if(n%i==0&&fuck){
            if(__gcd(i,n/i)==1){
                a=n/i,b=i;
                fuck=false;
            }
        }
    }
    if(fuck){
        printf("NO");
        return 0;
    }
    int t1=1,t2=-1,t;
    //printf("%d %d\n",a,b);
    while(((1-t1*a)%b)&&(((1-t2*a)%b))){
        t1++,t2--;
    }
    if(((1-t1*a)%b)==0)
        t=t1;
    else t=t2;
    int s=(1-t*a)/b;
    printf("YES\n%d\n",2);
//    (n-1)/n=n-t*a-s*b
    if(b*s<0){
        printf("%d %d\n",(-b*s)/b,a);
        printf("%d %d\n",(n-t*a)/a,b);
    }
    else{
        printf("%d %d\n",(-t*a)/a,b);
        printf("%d %d\n",(n-s*b)/b,a);
    }
}