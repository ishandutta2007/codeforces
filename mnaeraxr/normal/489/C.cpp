#include <iostream>
#include <vector>

using namespace std;

bool valid(int M, int S)
{
    return S >= 0 && 9 * M >= S;
}

int main()
{
    int m, s; cin >> m >> s;
    
    if (m == 1 && s == 0)
    {
        cout << "0 0" << endl;
        return 0;
    }
    
    if ((s == 0 && m > 1) || !valid(m, s))
    {
        cout << "-1 -1" << endl;
        return 0;
    }
    
    int cs = s;
    for (int i = 0; i < m; ++i)
    {
        for (int d = 0; d < 10; ++d)
        {
            if (i == 0 && d == 0) continue;
            if (valid(m - i - 1, cs - d))
            {
                cout << d;              
                cs -= d;
                break;
            }
        }
    }
    cout << " ";
    cs = s;
    for (int i = 0; i < m; ++i)
    {
        for (int d = 9; d > -1; --d)
        {
            if (i == 0 && d == 0) continue;
            if (valid(m - i - 1, cs - d))
            {
                cout << d;
                cs -= d;
                break;
            }
        }
    }
    cout << endl;
    //system("pause");
    return 0;
}