#include <bits/stdc++.h>
#define ll long long
#define _INFINITY 9223372036854775807
using namespace std;

int main()
{
    map<string, bool> c;
    string command;
    int r = 0;
    while (getline(cin, command))
    {
        if(command.empty())
            break;
        if (command[0] == '+')
            c[command.substr(1)] = 1;
        else if (command[0] == '-')
            c.erase(command.substr(1));
        else
            r += (command.length() - command.find(':') - 1) * c.size();
    }
    cout << r;
}