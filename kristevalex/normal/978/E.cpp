#include <bits/stdc++.h>
using namespace std;

int n, w;


bool exists[1001] = {};

vector<int> input;

stack<int> data;

int main()
{
    cin >> n >> w;

    input.resize(n);

    for (size_t i = 0; i < n; i++)
        cin >> input[i];

    int MAX = max(input[0], 0), MIN = min(0, input[0]);




    for (int i = 1; i < n; i++)
        {
        input[i]+= input [i-1];
        if (input[i] > MAX) MAX = input[i];
        if (input[i] < MIN) MIN = input[i];
        }
    //MAX = w-MAX;
    //MIN = -MIN;
    if ((w - MAX + MIN + 1) < 0) cout << 0 << endl;
    else cout << w - MAX + MIN + 1 << endl;
}