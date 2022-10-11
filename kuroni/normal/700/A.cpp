#include<bits/stdc++.h>
main(){double n,k,v,u,l,x;std::cin>>n>>l>>v>>u>>k;int t=(n-1)/k+1;x=(v+u)*l/((2*t-1)*v+u);printf("%f",x/u+(l-x)/v);}