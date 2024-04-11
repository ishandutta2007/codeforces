#include <iostream>
using namespace std;
int gcd(int a, int b){
    return b==0?a:gcd(b,a%b);
}
int main(){
    int n,m=-1,g=0,x,i;
    cin>>n;
    for(i=0;i<n;++i){
        cin>>x;
        m=max(m,x);
        g=gcd(g,x);
    }
    cout<<((m/g-n)%2?"Alice":"Bob")<<endl;  
    return 0;
}