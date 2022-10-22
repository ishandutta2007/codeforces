#include <iostream>
using namespace std;

int main()
{
    int n, sum = 0, minodd = -1;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp; sum += tmp;
        if (tmp % 2 && (minodd == -1 || tmp < minodd)) minodd = tmp;
    }
    if (sum % 2) cout << sum << endl;
    else if (minodd != -1) cout << sum - minodd << endl;
         else cout << "0\n";
    return 0;
}