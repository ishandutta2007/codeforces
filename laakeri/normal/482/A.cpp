#include <iostream>

using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    int lol=k;
    int a=1;
    for (int i=0;i<=k;i++){
        cout<<a<<" ";
        if (i%2==0) a+=lol;
        else a-=lol;
        lol--;
    }
    for (int i=k+2;i<=n;i++){
        cout<<i<<" ";
    }
}