#include<bits/stdc++.h>
using namespace std;
int main() {
    long double h,l;
    scanf("%Lf %Lf",&h,&l);
    printf("%.8Lf",(h*h+l*l)/(2*h)-h);
    return 0;
}