#include <iostream>
#include <cmath>

using namespace std;

typedef long long ll;

int main(){
    ll r,x,y,x2,y2;
    cin>>r>>x>>y>>x2>>y2;
    ll d=(x-x2)*(x-x2)+(y-y2)*(y-y2);
    ll mi=0;
    ll ma=1e8/r;
    ma++;
    while (mi<=ma){
        ll m=(mi+ma)/2ll;
        if ((r*m*2ll)*(r*m*2ll)>=d){
            ma=m-1;
        }
        else{
            mi=m+1;
        }
    }
    cout<<mi<<endl;
}