#include <iostream>

using namespace std;

int main(){
    int n,m,mi,ma;
    cin>>n>>m>>mi>>ma;
    int neemi=1;
    int neema=1;
    for (int i=0;i<m;i++){
        int a;
        cin>>a;
        if (a==mi){
            neemi=0;
        }
        if (a==ma){
            neema=0;
        }
        if (a<mi){
            cout <<"Incorrect"<<endl;
            return 0;
        }
        if (a>ma){
            cout <<"Incorrect"<<endl;
            return 0;
        }
    }
    int nee=neemi+neema;
    if (n-m<nee){
        cout <<"Incorrect"<<endl;
    }
    else{
        cout <<"Correct"<<endl;
    }
}