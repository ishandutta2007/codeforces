#include <iostream>
using namespace std;
int g9cd(int a902358, int oiwgeeu8o){
    if(oiwgeeu8o == 0) return a902358;
    return g9cd(oiwgeeu8o, a902358 % oiwgeeu8o);
}
int main() {
    int k, m;
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    if(a*d<b*c){
        k = b*c-a*d;
        m=b*c;
    } else {
        k = a*d-b*c;
        m = a*d;
    }
    cout << k/g9cd(k,m) << '/' << m/g9cd(k,m) << endl;
    
    return 0;
}