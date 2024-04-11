#include<iostream>
#include<string.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (n % 2 == 1){
        cout << ":(\n";
        return 0;
    }
    int o = 0, c = 0, q = 0;
    for (int i = 0; i < n; ++i){
        if (s[i] == '(') o++;
        if (s[i] == ')') c++;
        if (s[i] == '?') q++;
    }
    if (o > n / 2 || c > n / 2){
        cout << ":(\n";
        return 0;
    }
    int to_open = n / 2 - o;
    int b = 0;
    for (int i = 0; i < n; ++i){
        if (s[i] == '(') b++;
        if (s[i] == ')') b--;
        if (s[i] == '?'){
            if (to_open) {
                to_open--;
                s[i] = '(';
                b++;
            } else{
                s[i] = ')';
                b--;
            }
        }
        if (b <= 0 && i != n - 1){
            cout << ":(\n";
            return 0;
        }
    }
    cout << s << endl;
}