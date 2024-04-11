//
#include<bits/stdc++.h>
using namespace std;int T;long long X,Y,c1,c2,c3,c4,c5,c6;
inline long long calc(int x) {int a1=x,a2=Y-a1,a3=a1-X;return (a1>0?c1:-c4)*a1+(a2>0?c2:-c5)*a2+(a3>0?c3:-c6)*a3;}
int main() {for(scanf("%d",&T);T--;) scanf("%lld%lld%lld%lld%lld%lld%lld%lld",&X,&Y,&c1,&c2,&c3,&c4,&c5,&c6),printf("%lld\n",min(calc(0),min(calc(X),calc(Y))));}