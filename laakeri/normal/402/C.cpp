#include <iostream>

using namespace std;

int main(){
    int t;
    cin>>t;
    for (int a=0;a<t;a++){
        int n,p;
        cin>>n>>p;
        p+=2*n;
        for (int i=1;i<=n;i++){
            for (int ii=i+1;ii<=n;ii++){
                cout <<i<<" "<<ii<<endl;
                p--;
                if (!p){
                    break;
                }
            }
            if (!p){
                break;
            }
        }
    }
}