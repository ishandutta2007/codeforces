#include <iostream>

using namespace std;

int isc[1000001];

int main(){
    for (int i=2;i<=1000000;i++){
        if (!isc[i]){
            for (int ii=i+i;ii<=1000000;ii+=i){
                isc[ii]=1;
            }
        }
    }
    int n;
    cin>>n;
    for (int i=1;i<n;i++){
        if (isc[i]&&isc[n-i]){
            cout<<i<<" "<<n-i<<endl;
            return 0;
        }
    }
}