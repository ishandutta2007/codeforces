#include <iostream>
#include <cmath>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    double a,d;
    cin>>a>>d;
    d=fmod(d,a*4);
    int n;
    cin>>n;
    double c=0;
    for (int i=0;i<n;i++){
        c+=d;
        c=fmod(c,a*4);
        if (c<=a){
            cout <<c<<" 0"<<endl;
        }
        else if (c<=2*a){
            cout <<a<<" "<<c-a<<endl;
        }
        else if (c<=3*a){
            cout <<(a-(c-2*a))<<" "<<a<<endl;
        }
        else {
            cout <<"0 "<<(a-(c-3*a))<<endl;
        }
    }
}