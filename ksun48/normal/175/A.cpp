#include <iostream>
#include <string.h>
using namespace std;
int maxz = -1;
int main() {
    char polar[35];
    cin >> polar;
    int len = strlen(polar);
    for(int i = 1; i < len ; i++){
        for(int j = i+1; j < len; j++){
            if(i > 1 && polar[0] == '0'){
                continue;
            }
            if(i > 8 || j-i > 8 || len-j > 8){
                continue;
            }
            if(j-i > 1 && polar[i] == '0'){
                continue;
            }
            if(len-j > 1 && polar[j] == '0'){
                continue;
            }
            long long a = 0, b = 0, c = 0;
            for(int k = 0; k < i; k++){
                a *= 10;
                a += (polar[k]-'0');
            }
            for(int k = i; k < j; k++){
                b *= 10;
                b += (polar[k]-'0');
            }
            for(int k = j; k < len; k++){
                c *= 10;
                c += (polar[k]-'0');
            }
            if(a > 1000000 || b > 1000000 || c > 1000000){
            } else {
                if(a + b + c > maxz){
                    maxz = a + b + c;
                    //cout << a << " " << b << " " << c << " " << (a + b + c);
                }
            }
        }
    }
    cout << maxz << endl;
    return 0;
}