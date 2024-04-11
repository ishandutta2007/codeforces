#include <iostream>
using namespace std;
int ab2s(int x){
if(x < 0) return -x;
return x;
}
int main() {
    int a, b;
    cin >> a >> b;
    int c = 0;
    int d=  0;
    int e = 0;
    for(int x = 1; x <= 6; x++){
        if(ab2s(a-x) < ab2s(b-x)){
            c++;
        } else if(ab2s(a-x) == ab2s(b-x)){
            d++;
        } else {
            e++;
        }
    }
    cout<< c << " " << d << " " << e << endl;
    return 0;
}