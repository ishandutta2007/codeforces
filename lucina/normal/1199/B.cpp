#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
double l,h;

int main(){
    cin>>h>>l;
    double ans=(l*l-h*h)/(2.0*h);
    printf("%.12f\n",ans);
}
/*
    Good Luck
        -Lysithea
*/