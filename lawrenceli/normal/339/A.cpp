#include <iostream>
#include <algorithm>
using namespace std;
string s;
int arr[200];
int main() {
    cin >> s;
    for (int i=0; i<=s.length()/2; i++) arr[i] = s[2*i] - '0';
    sort(arr, arr + s.length()/2 + 1);
    for (int i=0; i<=s.length()/2; i++) {
        cout << char(arr[i] + '0');
        if (i < s.length()/2) cout << '+';
    }
}