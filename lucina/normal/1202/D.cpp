#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int t;
long long n;

int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%lld",&n);
        long long x=1LL;
        while(x*(x-1)<=2*n)x++;
        x--;
        long long res=n-(x*(x-1)/2);
        printf("1");
        for(int i=0;i<x-2;i++){
            printf("3");
        }
        for(int i=0;i<res;i++){
            printf("1");
        }
        printf("337\n");
    }
}
/*
    Good Luck
        -Lucina
*/