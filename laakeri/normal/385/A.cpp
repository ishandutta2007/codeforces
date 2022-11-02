#include <iostream>
#include <vector>

using namespace std;

int asd[110];

int main(){
    int n;
    int c;
    cin>>n>>c;
    int pr=0;
    for (int i=0;i<n;i++){
        cin>>asd[i];
        if (i>0){
            pr=max(asd[i-1]-asd[i]-c,pr);
        }
    }
    cout <<pr<<endl;
}