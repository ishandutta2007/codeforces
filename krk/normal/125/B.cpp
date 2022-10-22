#include <iostream>
#include <string>
using namespace std;

string s;
int h;

int main()
{
    getline(cin, s);
    for (int i = 0; i < s.length(); ) {
        int len;
        if (s[i + 1] == '/') { len = 4; h--; }
        else len = 3;
        for (int j = 0; j < 2 * h; j++)
            cout << " ";
        if (s[i + 1] != '/') h++;
        cout << s.substr(i, len) << endl;
        i += len;
    }
    return 0;
}