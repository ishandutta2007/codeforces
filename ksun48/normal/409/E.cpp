#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double a;
    cin >> a;
    int yes = 0;
    for(int i = 1; i <=10; i++){
        for(int j = 1; j <= 10; j++){
            double c = i;
            double d = j;
            double e = c*d/sqrt(4*d*d+c*c);
            if(e > a-0.00001 && a > e-0.00001){
                cout << i << " " << j << endl;
                yes = 1;
                break;
            }
        }
        if(yes) break;
    }
    return 0;
}