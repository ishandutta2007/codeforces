#include <bits/stdc++.h>
using namespace std;

int n;


bool exists[1001] = {};

vector<int> input;

stack<int> data;

int main()
{
    cin >> n;

    input.resize(n);

    for (size_t i = 0; i < n; i++)
        cin >> input[i];

    //cout << 1;

    for (int i = n-1; i >= 0; i--)
        {
        //cout << i;

        if (exists[input[i]]) continue;
        else
            {
            exists[input[i]] = true;
            data.push(input[i]);
            }
        //cout << i;

        }

    cout << data.size() << endl;

    while (!data.empty())
        {
        cout << data.top() << " ";
        data.pop();
        }

}