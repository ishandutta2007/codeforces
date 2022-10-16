#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const string pok = "Bulbasaur";

vector<int> cnt(string s) {
    vector<int> res;
    for (char i = 'a'; i <= 'z'; ++i)
        res.push_back(count(s.begin(), s.end(), i));
    for (char i = 'A'; i <= 'Z'; ++i)
        res.push_back(count(s.begin(), s.end(), i));
    return res;
}

int divide(vector<int> a, vector<int> b) {
    int res = 1e6;
    for (int i = 0; i < a.size(); ++i)
        if (b[i])
            res = min(res, a[i] / b[i]);
    return res;
}

int main()
{
    string s;
    cin >> s;
    cout << divide(cnt(s), cnt(pok));
    return 0;
}