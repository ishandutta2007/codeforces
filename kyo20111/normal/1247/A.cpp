#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a,b;
int main(){
    scanf("%d %d",&a,&b);
    if(a == b) printf("%d %d",a*10,a*10+1);
    else if(a+1 == b) printf("%d %d",a,b);
    else if(a == 9 && b == 1) printf("9 10");
    else printf("-1");
}