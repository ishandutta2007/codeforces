#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int xp,yp,xv,yv;
    cin>>xp>>yp>>xv>>yv;
    int v=0;
    for (int i=0;i<=min(xv, yv);i++){
        int x=xv-i;
        int y=yv-i;
        if (x<=xp&&y<=yp){
            if (xp-x+(yp-y)<=i){
                break;
            }
        }
        if (i+x+y<xp+yp){
            v=1;
        }
    }
    if (v){
        cout<<"Vasiliy"<<endl;
    }
    else{
        cout<<"Polycarp"<<endl;
    }
}