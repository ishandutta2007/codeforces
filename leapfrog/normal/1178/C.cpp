#include<bits/stdc++.h>
using namespace std;const int P=998244353;int n,m;
inline int ksm(int x,int q) {int r=1;for(;q;q>>=1,x=1ll*x*x%P) if(q&1) r=1ll*x*r%P;return r;}
int main() {return scanf("%d%d",&n,&m),printf("%d\n",ksm(2,n+m)),0;}