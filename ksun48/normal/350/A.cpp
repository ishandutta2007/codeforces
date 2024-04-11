#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    int str1[a];
    int str2[b];
    for(int i = 0; i < a; i++) cin >> str1[i];
    for(int i = 0; i < b; i++) cin >> str2[i];
    sort(str1, str1+a);
    sort(str2, str2+b);
    int k = max(2*str1[0], str1[a-1]);
    if(k >= str2[0]){
        cout << -1 << endl;
    } else {
        cout << k << endl;
    }
    return 0;
}