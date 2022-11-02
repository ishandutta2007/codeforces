#include <iostream>
#include <set>
#include <algorithm>
#define F first
#define S second

using namespace std;

int abs(int x){
    if (x<0) return -x;
    return x;
}

int main(){
    int n,x,y;
    cin>>n>>x>>y;
    set<pair<int, int> > lol;
    for (int i=0;i<n;i++){
        pair<int, int> asd;
        cin>>asd.F>>asd.S;
        asd.F-=x;
        asd.S-=y;
        if (asd.F==0){
            asd.S=1;
        }
        else if (asd.S==0){
            asd.F=1;
        }
        else{
            int g=__gcd(abs(asd.F), abs(asd.S));
            asd.F/=g;
            asd.S/=g;
        }
        if (asd.F<0&&asd.S<0) {
            asd.F=-asd.F;
            asd.S=-asd.S;
        }
        if (asd.F<0&&asd.S>0){
            asd.F=-asd.F;
            asd.S=-asd.S;
        }
        //cout<<asd.F<<" "<<asd.S<<endl;
        lol.insert(asd);
    }
    cout<<lol.size()<<endl;
}