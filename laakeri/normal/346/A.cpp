#include <iostream>
#include <cmath>

using namespace std;

int gcd(int a, int b){
    if (a%b==0) return b;
    return gcd(b, a%b);
}

int main(){
    int n;
    cin>>n;
    int d;
    int ma=0;
    for (int i=0;i<n;i++){
        int a;
        cin>>a;
        if (i) d=gcd(a, d);
        else d=a;
        ma=max(ma, a);
    }
    if ((ma/d-n)%2==1){
        cout<<"Alice"<<endl;
    }
    else{
        cout<<"Bob"<<endl;
    }
}