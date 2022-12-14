#include <bits/stdc++.h>
using namespace std;

struct ind_int
    {
    int x, ind;

    bool operator< (ind_int over)
        {
        return (x < over.x);
        }
    };

int n;
string text;

vector<ind_int> data;

stack<int> sequence;

int main()
    {
    cin >> n;

    data.resize(n);

    for (size_t i = 0; i < n; i++)
        {
        cin >> data[i].x;
        data[i].ind = i+1;
        }

    cin >> text;

    sort (data.begin(), data.end());

    for (size_t i = 0, j = 0; i < 2*n; i++)
        {
        if (text[i] == '0')
            {
            cout << data[j].ind << " ";
            sequence.push(data[j].ind);
            j++;
            }
        else
            {
            cout << sequence.top() << " ";
            sequence.pop();
            }
        }



    return 0;

    }