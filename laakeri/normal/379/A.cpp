#include <iostream>

using namespace std;

int main() {
    int a;
    int b;
    cin>>a>>b;
    int v=0;
    int vo=0;
    while (a>0){
        v+=a;
        vo+=a;
        a=vo/b;
        vo=vo%b;
    }
    cout << v << endl;
}