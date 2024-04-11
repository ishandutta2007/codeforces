#include <iostream>

using namespace std;

int main(){
    int n;
    int m;
    cin>>n>>m;
    for (int d=1;;d++){
        if (n==0){
            cout<<d-1<<endl;
            return 0;
        }
        n--;
        if (d%m==0){
            n++;
        }
    }
}