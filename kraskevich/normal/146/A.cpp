#include <iostream>
#include <fstream>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    bool ok = true;
    for(int i = 0; i < n; ++i)
            if(s[i] != '4'&& s[i] != '7')
                    ok = false;
    int sum = 0;
    for(int i = 0; i < n / 2; ++i)
            sum += s[i] - s[n - 1 - i];
   ok = ok & (sum == 0);
   cout << (ok ? "YES" : "NO");
   cin >> n;
   return 0;   
}