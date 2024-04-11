#include<bits/stdc++.h>
using namespace std;

int h[50],w[50];

int main(){
    int N;
    cin>>N;
    for(int i=0;i<N*N;i++){
        int a,b;
        cin>>a>>b;
        a--;b--;
        if(h[a]||w[b])continue;
        h[a]=w[b]=true;
        cout<<i+1<<" ";
    }
    cout<<endl;

    return 0;
}