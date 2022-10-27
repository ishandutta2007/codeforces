#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n,a;
int main(){
    scanf("%d",&n);
    int x=sqrt(n);
    int dif=n-x*x;
    a=2*x;
    if(dif>x)
        a+=2;
    else if(dif>0)
        a++;
    printf("%d",a);

}