#include <iostream>

using namespace std;

int main()
{
    string s;
    int sum = 0;
    cin >> s;
    for (auto i: s) if (isalpha(i))
        sum += (i > '@' && i < '[') * (tolower(i) - 'a' + 1) - (i > '`' && i < '{') * (tolower(i) - 'a' + 1);
    cout << int(sum);
    return 0;
}