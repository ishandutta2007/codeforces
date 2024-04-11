#include<cstdio>
const int N=1000002;
int n,m,cnt;
int main(){
    scanf("%d%d",&n,&m);
    if(m%n){
        printf("-1");
        return 0;
    }
    m/=n;
    while(m%3==0)
    m/=3,cnt++;
    while(m%2==0)
    m/=2,cnt++;  
    if(m!=1){
        printf("-1");
        return 0;
    }
    printf("%d",cnt);
}