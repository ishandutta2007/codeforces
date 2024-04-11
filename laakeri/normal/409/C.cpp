#include <iostream>

using namespace std;

int main(){
    int a1,a2,a3,a4,a5;
    cin>>a1>>a2>>a3>>a4>>a5;
    int mi=999;
    mi=min(mi,a1);
    mi=min(mi,a2);
    mi=min(mi,a3/2);
    mi=min(mi,a4/7);
    mi=min(mi,a5/4);
    cout <<mi<<endl;
}