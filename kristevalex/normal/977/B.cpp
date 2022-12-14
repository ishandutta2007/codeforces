#include <bits/stdc++.h>
using namespace std;


int n;
char previous, current;

int MAX = 1;
pair<char, char> MAX_pair;
int current_value = 1;



vector<pair<char, char>> pairs;

int main()
    {
    cin >> n >> current;

    pairs.resize(n-1);

    for (size_t i = 0; i < n-1; i++)
        {
        previous = current;
        cin >> current;

        pairs[i].first = previous;
        pairs[i].second = current;
        }

    sort(pairs.begin(), pairs.end());

    MAX_pair = pairs[0];


    for (size_t i = 1; i < n-1; i++)
        {
        if (pairs[i] == pairs[i-1]) current_value++;
        else current_value = 1;
        if (current_value > MAX)
            {
            MAX = current_value;
            MAX_pair = pairs[i];
            }
        }

    cout << MAX_pair.first << MAX_pair.second;

    return 0;
    }