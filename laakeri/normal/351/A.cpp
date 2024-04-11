#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main(){
    int n;
    cin>>n;
    int o=0;
    double t=0.000;
    for (int i=0;i<n*2;i++){
        double a;
        cin>>a;
        if (a-floor(a)>0.000001){
            o++;
            t-=a-floor(a);
        }
    }
    int pop=min(o, n);
    if (o>n){
        t+=(double)(o-n);
        pop-=(o-n);
    }
    double b=abs(t);
    for (int i=0;i<pop;i++){
        t+=1.0000;
        b=min(b, abs(t));
    }
    cout<<fixed<<setprecision(3)<<b<<endl;
}