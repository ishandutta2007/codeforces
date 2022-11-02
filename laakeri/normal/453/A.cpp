#include <iostream>
#include <iomanip>

using namespace std;

typedef long double ld;

ld pow (ld x, int p){
    if (p==0) return 1.0;
    if (p%2==0) return pow(x,p/2)*pow(x,p/2);
    else return x*pow(x,p-1);
}

int main(){
    int n,m;
    cin>>m>>n;
    ld v=0;
    for (int i=1;i<=m;i++){
        v+=(ld)i*pow((ld)i/(ld)m,n);
        if (i<m){
            v-=(ld)(i+1)*pow((ld)i/(ld)m,n);
        }
    }
    cout<<setprecision(10)<<v<<endl;
}