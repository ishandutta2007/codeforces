#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <utility>

using namespace std;


int main()
{
    string n;
    int count = 0;
    cin >> n;
    bool start = true;
    for (int i = 0; i < n.length(); i++)
    {
        int a = (int)(n[i] - '0');
        if (a == 9 && start){
            cout << 9;
        }
        else if (a > 4)
            cout << 9 - a;
        else
            cout << a;
        start = false;
    }
    cout << endl;


    return 0;
}