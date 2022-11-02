#include <iostream>

using namespace std;

int main(){
    int n;
    cin>>n;
    int pf=0;
    int v=0;
    for (int i=0;i<n;i++){
        int a;
        cin>>a;
        if (a>0){
            pf+=a;
        }
        if (a==-1){
            if (pf<1) v++;
            else pf--;
        }
    }
    cout <<v<<endl;
}