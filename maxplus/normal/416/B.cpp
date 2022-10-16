#include <iostream>
int t[500000][10];
int ft[500000][10];
int main(){
int n,m;
std::cin>>n>>m;
for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)std::cin>>t[i][j];
for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)ft[i][j]=std::max(ft[i-1][j]+t[i][j],ft[i][j-1]+t[i][j]);
for(int i=1;i<=n;++i)std::cout<<ft[i][m]<<' ';
return 0;}