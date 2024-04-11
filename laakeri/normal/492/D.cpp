#include <iostream>
#include <cmath>

using namespace std;

int lol[2000011];

typedef long double ld;

const ld e=1e-13;

int main(){
    int n,x,y;
    cin>>n>>x>>y;
    ld a=0;
    ld b=0;
    ld xx=1.00000000000000/x;
    ld yy=1.00000000000000/y;
    for (int i=1;i<=x+y;i++){
        //cout<<xx<<" "<<yy<<endl;
        //cout<<abs(a+xx-(b+yy))<<endl;
        if (abs(a+xx-(b+yy))<=e){
            lol[i]=2;
            i++;
            lol[i]=2;
            a+=xx;
            b+=yy;
        }
        else if(a+xx<b+yy){
            lol[i]=0;
            a+=xx;
        }
        else {
            lol[i]=1;
            b+=yy;
        }
        //cout<<a<<" ab "<<b<<endl;
        //cout<<i<<" "<<lol[i]<<endl;
    }
    for (int i=0;i<n;i++){
        int a;
        cin>>a;
        a%=(x+y);
        if (a==0||lol[a]==2){
            cout<<"Both"<<'\n';
        }
        else if(lol[a]==0){
            cout<<"Vanya"<<'\n';
        }
        else if(lol[a]==1){
            cout<<"Vova"<<'\n';
        }
    }
}