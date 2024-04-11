#include <iostream>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <vector>
#include <math.h>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <ctime>

#define MP make_pair
#define PB push_back
#define F first
#define S second
#define prev azazan

using namespace std;

typedef long long ll;

const int max_n = 300111, inf = 1000111222;

vector<int> pos;
bool arr[max_n];


int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int cur_p;
        cin >> cur_p;
        --cur_p;
        pos.PB(cur_p);
    }
    int pos0 = n - 1;
    int cnt1 = 0;
    cout << 1 << ' ';
    for (int i = 0; i < n; ++i) {
        int curp = pos[i];
        if (curp < pos0) {
            arr[curp] = 1;
            cnt1++;
        } else {
            cnt1++;
            arr[curp] = 1;
            while(pos0 >= 0 && arr[pos0]) {
                --pos0;
                --cnt1;
            }
        }
        cout << cnt1 + 1 << ' ';
    }
    cout << endl;
    return 0;
}