#include <bits/stdc++.h>
using namespace std;

int n;
vector<string> data;


int main()
    {
    cin >> n;

    data.resize(n);

    bool stock[6] = {};

    for (int i = 0; i < n; i++)
        {
        cin >> data[i];
        if (data[i] == "purple") stock[0] = true;
        if (data[i] == "green")  stock[1] = true;
        if (data[i] == "blue")   stock[2] = true;
        if (data[i] == "orange") stock[3] = true;
        if (data[i] == "red")    stock[4] = true;
        if (data[i] == "yellow") stock[5] = true;
        }

    cout << 6-n << endl;

    if (!stock[0]) cout << "Power" << endl;
    if (!stock[1]) cout << "Time" << endl;
    if (!stock[2]) cout << "Space" << endl;
    if (!stock[3]) cout << "Soul" << endl;
    if (!stock[4]) cout << "Reality" << endl;
    if (!stock[5]) cout << "Mind" << endl;

    return 0;
    }