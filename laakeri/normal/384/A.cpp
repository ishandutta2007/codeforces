#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin>>n;
    cout <<(n/2)*(n/2)+(n/2+n%2)*(n/2+n%2)<<endl;
    for (int i=0;i<n;i++){
        for (int ii=0;ii<n;ii++){
            if (i%2==ii%2){
                cout <<"C";
            }
            else {
                cout <<".";
            }
        }
        cout <<endl;
    }
}