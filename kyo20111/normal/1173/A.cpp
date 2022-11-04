#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a,b,c;
int main(){
    scanf("%d %d %d",&a,&b,&c);
    if(c && abs(a-b) <= c) return !printf("?");

    if(a > b) printf("+");
    if(a < b) printf("-");
    if(a == b) printf("0");
}