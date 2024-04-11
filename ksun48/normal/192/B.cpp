#include <iostream>
using namespace std;
int Min(int a, int b) {
  return (a < b ? a : b);
}
int Max(int a, int b) {
  return (a > b ? a : b);
}
int main() {
    int k; cin >> k;
    int tiles[k];
    for(int i = 0; i < k; i++){
        cin >> tiles[i];
    }
    int days = 10000;
    days = Min(days, tiles[0]);
    days = Min(days, tiles[k-1]);
    for(int i = 0; i < k-1; i++){
        days = Min(days, Max(tiles[i], tiles[i+1]));
    }
    cout << days << endl;
    return 0;
}