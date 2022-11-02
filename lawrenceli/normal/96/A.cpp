#include <iostream>
using namespace std;

int main()
{
    string s;
    cin >> s;
    if (s.length()<7)
    {
        cout << "NO" << endl;
        return 0;
    }
    for (int i=0; i<=s.length()-7; i++)
    {
        if (s.substr(i, 7)=="0000000" || s.substr(i, 7)=="1111111")
        {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
}