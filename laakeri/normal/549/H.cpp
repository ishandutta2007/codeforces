#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef long double ld;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ld a,b,c,d;
    cin>>a>>b>>c>>d;
    ld mi=0;
    ld ma=1e9;

    for (int i=0;i<1000;i++){
        ld m=(mi+ma)/(ld)2;
        ld mi1=min(min((a+m)*(d+m), (a-m)*(d+m)), min((a+m)*(d-m), (a-m)*(d-m)));
        ld ma1=max(max((a+m)*(d+m), (a-m)*(d+m)), max((a+m)*(d-m), (a-m)*(d-m)));

        ld mi2=min(min((b+m)*(c+m), (b-m)*(c+m)), min((b+m)*(c-m), (b-m)*(c-m)));
        ld ma2=max(max((b+m)*(c+m), (b-m)*(c+m)), max((b+m)*(c-m), (b-m)*(c-m)));
        if (mi1-ma2<0&&ma1-mi2>0){
            ma=m;
        }
        else{
            mi=m;
        }
        //cout<<setprecision(30)<<mi<<" "<<ma<<endl;
    }
    cout<<setprecision(15)<<mi<<endl;
}