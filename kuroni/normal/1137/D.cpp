#include <iostream>
#include <cstdio>
using namespace std;

int val, cnt = 0;

int ask(string s)
{
    cout << "next ";
    for (char &c : s)
        cout << c << " ";
    cout << endl;
    int ret;
    cin >> ret;
    for (int i = 0; i < ret; i++)
        cin >> s;
    return ret;
}

int main()
{
    do
    {
        ++cnt;
        ask("01");
        val = ask("0");
    } while (val != 2);
    do
    {
        val = ask("0123456789");
    } while (val != 1);
    cout << "done" << endl;
}