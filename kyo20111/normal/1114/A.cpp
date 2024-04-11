#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a,b,c,d,e,f;
int main(){
    scanf("%d %d %d %d %d %d",&a,&b,&c,&d,&e,&f);
    if(a > d || b > (d-a)+e || c > d+e+f-a-b) printf("No");
    else printf("Yes");
}