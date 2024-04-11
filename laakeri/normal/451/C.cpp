#include <iostream>

using namespace std;

typedef long long ll;

int main(){
    int t;
    cin>>t;
    for (int i=0;i<t;i++){
        ll n,k,d1,d2,j;
        cin>>n>>k>>d1>>d2;
        j=n-k;
        //t1
        if (k>=(ll)2*d1+d2&&(k-((ll)2*d1+d2))%(ll)3==(ll)0){
            if (j>=d1+(ll)2*d2&&(j-(d1+(ll)2*d2))%(ll)3==(ll)0){
                cout<<"yes"<<'\n';
                continue;
            }
        }
        //t2
        if (k>=d1+d2&&(k-(d1+d2))%(ll)3==(ll)0){
            ll asd=max(d1,d2)+max(d1,d2)-min(d1,d2);
            if (j>=asd&&(j-asd)%(ll)3==(ll)0){
                cout<<"yes"<<'\n';
                continue;
            }
        }
        //t3
        ll asd=max(d1,d2)+max(d1,d2)-min(d1,d2);
        if (k>=asd&&(k-asd)%(ll)3==(ll)0){
            if (j>=d1+d2&&(j-(d1+d2))%(ll)3==(ll)0){
                cout<<"yes"<<'\n';
                continue;
            }
        }
        //t4
        if (k>=d1+(ll)2*d2&&(k-(d1+(ll)2*d2))%(ll)3==(ll)0){
            if (j>=(ll)2*d1+d2&&(j-((ll)2*d1+d2))%(ll)3==(ll)0){
                cout<<"yes"<<'\n';
                continue;
            }
        }
        cout<<"no"<<'\n';
    }
}