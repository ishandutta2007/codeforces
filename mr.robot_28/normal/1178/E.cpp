#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
int main() {
    string S; cin >> S;
    int N = S.size();
    int i = 0, j = N-1;
    string A;
    while (j-i >= 3) {
        if (S[i] == S[j]) {
            A.push_back(S[i]);
            ++i; --j;
        } else if (S[i] == S[j-1]) {
            A.push_back(S[i]);
            ++i; j -= 2;
        } else {
            A.push_back(S[i+1]);
            if (S[i+1] == S[j]) {
                --j;
            } else {
                j -= 2;
            }
            i += 2;
        }
    }
    string B = A;
    if (j >= i) A.push_back(S[i]);
    reverse(B.begin(),B.end());
    cout << A << B << endl;
}