#include <bits/stdc++.h>
using namespace std;
void eat(){
    int x,y=360;
    cin>>x;
    int g=gcd(x,y);
    x/=g,y/=g;
    if(y&1){
        x<<=1;
        g>>=1;
        y<<=1;
    }
    if((180-x*g)*(y>>1)<360)y<<=1;
    cout<<(y>>1)<<"\n";
}
int main(){
    int t;
    cin>>t;
    while(t--)eat();
}