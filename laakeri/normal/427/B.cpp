#include <iostream>

using namespace std;

int main(){
    int n,t,c;
    cin>>n>>t>>c;
    int has=0;
    int v=0;
    for (int i=0;i<n;i++){
        int a;
        cin>>a;
        if (a>t){
            has=0;
        }
        else{
            has++;
            if (has==c){
                v++;
                has--;
            }
        }
    }
    cout <<v<<endl;
}