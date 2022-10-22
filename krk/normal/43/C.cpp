#include <iostream>
#include <algorithm>
using namespace std;

int pieces[3];

int main()
{
    int i, a, n;
    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> a;
        pieces[a % 3]++;
    }
    cout << min(pieces[1], pieces[2]) + pieces[0]/2 << endl;
    return 0;
}