#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int c[n];
    for(int i = 0; i < n; ++i){
        cin >> c[i];
    }
    int i = 0;
    int j = n - 1;
    while (c[i] == c[j])i++;
    int S1 = j - i;
    i = 0;
    j = n - 1;
    while (c[i] == c[j])j--;
    int S2 = j - i;
    std::cout << max(S1, S2) << std::endl;
    return 0;
}