// tested
#include<bits/stdc++.h>
 
using namespace std;
#define no return !printf("NO")
 
int main(){
    int a,b,c,d;
    scanf("%d%d%d%d",&a,&b,&c,&d);
    ////// added part    
    if(b + 1 == a){
        if(! (c == 0 && d == 0)) no;
        printf("YES\n");
        for(int i = 1 ;i <= b ; i ++){
            printf("0 1 ");
        }
        printf("0");
        return 0;
    }
    if(d == c + 1){
        if(! (a == 0 && b ==0) ) no;
        printf("YES\n");
        for(int i = 1 ;i <= c; i ++){
            printf("3 2 ");
        }
        printf("3");
        return 0;
    }
    /////
    if(a > b || d > c) return !printf("NO");
    swap(b,a);
    a-=b;
    c-=d;
    if(abs(a-c) > 1) return !printf("NO");
    printf("YES\n");
    if(a > c) printf("1 "),a--;
    for(int i = 0;i<b;i++){
        printf("0 1 ");
    }
    for(int i = 0; i <  a;i++){
        printf("2 1 ");
    }
    for(int i = 0; i < d;i++){
        printf("2 3 ");
    }
    if(c > a) printf("2");
 
 
}