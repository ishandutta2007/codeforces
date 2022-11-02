#include <stdio.h> 
#include <algorithm> 
#include <vector> 
#include <string> 
using namespace std; 

int main(){ 
#pragma comment(linker, "/STACK:67108864") 
#pragma warning (disable : 4996) 
#ifndef ONLINE_JUDGE 
    freopen("input.txt", "rt", stdin); 
    freopen("output.txt", "wt", stdout); 
#endif 
    int i,n,m,j,x,a[111],m1; 
    scanf("%d%d",&n,&m); 
    if (n%2==0) m1=n/2; 
    else m1=(n/2)+1; 
    while(m1<n+1) { 
        if (m1%m==0) { 
            printf("%d",m1); 
            return 0; 
        } 
        m1++; 
    } 
    printf("%d",-1); 
    return 0; 
}