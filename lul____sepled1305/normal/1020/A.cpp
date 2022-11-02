#include<stdio.h>
long int n,h,a,b,k,l,i;
int main(){
    scanf("%ld %ld %ld %ld %ld",&n,&h,&a,&b,&k);
    long int problem[5][k+1];
    long int walk[5];
    for(i=1;i<=k;i++){
        scanf("%ld %ld %ld %ld",&problem[1][i],&problem[2][i],&problem[3][i],&problem[4][i]);
    }
    for(i=1;i<=k;i++){
        if(problem[1][i]==problem[3][i]){
            if(problem[2][i]>problem[4][i]){
                walk[0]=problem[2][i]-problem[4][i];
            }
            else{
                walk[0]=-problem[2][i]+problem[4][i];
            }
        }
        else
            {
        if(problem[2][i]>b){
            walk[1]=problem[2][i]-b;
            l=b;
        }
        else if(problem[2][i]<a){
            walk[1]=a-problem[2][i];
            l=a;
        }
        else {
            walk[1]=0;
            l=problem[2][i];
        }
        if(problem[1][i]<problem[3][i]){
            walk[2]=problem[3][i]-problem[1][i];
        }
        else {
            walk[2]=problem[1][i]-problem[3][i];
        }
        if(l>problem[4][i]){
            walk[3]=l-problem[4][i];
        }
        else{
            walk[3]=problem[4][i]-l;
        }
        walk[0]=walk[1]+walk[2]+walk[3];
            }
        printf("%ld\n",walk[0]);
    }
    return 0;
}