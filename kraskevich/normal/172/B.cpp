#include <iostream>
#include <map>
using namespace std;

int main() {
    long long a, b, r, m, res, cur;
    cin >> a >> b >> m >> r;
    map<int, int> was;
    was.insert(make_pair(r, 1));
    for(res = 2, cur = (a * r + b) % m; !was.count(cur); cur = (a * cur + b) % m, ++res) {was.insert(make_pair(cur, res));}
    cout << res - was[cur]; 
    return 0;
}