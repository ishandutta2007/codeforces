#include <iostream>

using namespace std;

int main()
{
    int A1, D1, A2, D2, a1, d1, a2, d2;
    cin >> A1 >> D1 >> A2 >> D2 >> a1 >> d1 >> a2 >> d2;
    if ((D1 > max(a1, a2) && A2 > max(d1, d2)) || (D2 > max(a1, a2) && A1 > max(d1, d2)))
        cout << "Team 1";
    else if (((D1 < a1 && A2 < d2) || (D1 < a2 && A2 < d1)) && ((D2 < a1 && A1 < d2) || (D2 < a2 && A1 < d1)))
        cout << "Team 2";
    else
        cout << "Draw";
    return 0;
}