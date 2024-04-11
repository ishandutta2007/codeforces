#include <iostream>
#include <string>
#include <set>
using namespace std;

int n;
set <string> S;
string s;

int main()
{
    cin >> n; cin.ignore();
    while (n--) {
          getline(cin, s);
          S.insert(s);
    }
    cout << S.size() << endl;
    return 0;
}