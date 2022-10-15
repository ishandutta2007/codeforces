#include <bits/stdc++.h>
#include <cmath>
using namespace std;
#define pi 3.14159265358979
int main(){
    cout<<fixed<<setprecision(9);
    int N;
    cin>>N;;
    while(N--){
        long double n;
        cin>>n;
        long double a=0.0;
        long double angle=180-((180*(2*n-2))/(2*n));
        long double inangle=angle;
        for(int i=0;i<n/2-1;i++){
            a=a+cos(angle*pi/180);
            angle=angle+inangle;
        }
        a=a*2;
        a=a+1;
        cout<<a<<"\n";
    }
}