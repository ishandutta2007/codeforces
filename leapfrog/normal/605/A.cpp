#include<bits/stdc++.h>
int n,k,f[1000005],rs;int main() {scanf("%d",&n),k=n;for(int x;n--;) scanf("%d",&x),rs=std::max(rs,f[x]=f[x-1]+1);printf("%d\n",k-rs);}