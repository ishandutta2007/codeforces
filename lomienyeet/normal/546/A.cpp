#include <bits/stdc++.h>
using namespace std;
int main(){
    long long K,N,W;
    cin>>K>>N>>W;
    long long fuck=K;
    for(long long i=1;i<W;i++)K+=(fuck*(i+1));
    if(K-N<0)cout<<"0\n";
    else cout<<K-N<<"\n";
}