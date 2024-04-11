#include <iostream>

using namespace std;

int main(){
    int k,a,b,v;
    cin>>k>>a>>b>>v;
    int va=0;
    while (a>0){
        int ms=min(k,b+1);
        b-=(ms-1);
        a-=ms*v;
        va++;
    }
    cout <<va<<endl;
}