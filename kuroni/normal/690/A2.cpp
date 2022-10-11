#include<bits/stdc++.h>
main(){int n;std::cin>>n;int k=n%2?n/2:(n-(int)pow(2,(int)log2(n)))/2;std::cout<<k;}