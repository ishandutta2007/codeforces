#include <iostream>

using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    int v=0;
    int b=0;
    for (int i=0;i<n;i++){
        int a;
        cin>>a;
        if (b+a>m){
            v++;
            b=a;
        }
        else{
            b+=a;
        }
    }
    cout <<v+1<<endl;
}