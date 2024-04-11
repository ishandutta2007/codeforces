#include <iostream>
using namespace std;

const int Maxn = 100000;

int n, ind, seq[Maxn];

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) cin >> seq[i];
    for (ind = 1; ind < n; ind++) if (seq[ind] != seq[ind-1]) break;
    if (ind == n) cout << "0\n";
    else {
         int i;
         for (i = ind+1; i < n; i++) 
            if (seq[0] < seq[ind] && seq[i-1] > seq[i] ||
                seq[0] > seq[ind] && seq[i-1] < seq[i]) break;
         if (i == n) cout << "0\n";
         else {
              cout << "3\n";
              cout << 1 << " " << i << " " << i+1 << endl; 
         }
    }
    return 0;
}