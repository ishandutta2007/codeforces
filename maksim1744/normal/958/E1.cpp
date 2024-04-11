#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int r, b;
    cin >> r >> b;
    if (r != b) {
        cout << "No";
        return 0;
    }
    cout << "Yes";
    return 0;
    vector<int> v;
    for (int i = 0; i < r; i++) {
        v.push_back(i);
    }

}