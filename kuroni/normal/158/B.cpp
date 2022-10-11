#include<iostream>
int A[5],N,i,t;
main(){
std::cin>>N;while(std::cin>>t)A[t]++;A[1]=std::max(A[1]-A[3],0);std::cout<<A[3]+A[4]+(A[1]+2*A[2]+3)/4;}