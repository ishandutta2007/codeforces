#include <iostream>

using namespace std;

int main()
{
    cin.get();
    int ans = 0;
    for (int i = 0; i < 6; ++i)
        ans += (cin.get() - '0' + 8) % 9 + 1;
    cout << ans + 1;
//    int a1, a2; a1 = cin.get() - '0'; a1 = (a1 * 10) + cin.peek() - '0'; a2 = cin.get() - '0'; a2 = (a2 * 10) + cin.peek() - '0';
//    for (int i = 0; i < 4; ++i)
//        cin.get();
//    cout << min(a1, a2);
    return 0;
}