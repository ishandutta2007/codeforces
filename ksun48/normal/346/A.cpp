#include <iostream>
using namespace std;
int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b,a%b);
}
int main() {
    int n;
    cin >> n;
    int m = 0;
    int g = 0;
    for(int i = 0; i < n; i++){
        int k;
        cin >> k;
        if(g == 0){
            g = k;
        } else {
            g = gcd(g,k);
        }
        m = max(m,k);
    }
    //cout << g << " " << m << endl;
    if((m/g-n) % 2){
        cout << "Alice" << endl;
    } else {
        cout << "Bob" << endl;
    }
    return 0;
}