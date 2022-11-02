#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> aa, bb, ans;
    int a, b;
    cin >> a >> b;
    if(!a)
          aa.push_back(0);
    while(a) {
             aa.push_back(a % 3);
             a /= 3;
    }
    if(!b)
          bb.push_back(0);
    while(b) {
             bb.push_back(b % 3);
             b /= 3;
    }
    while(aa.size() > bb.size())
                   bb.push_back(0);
    while(aa.size() < bb.size())
                   aa.push_back(0);
    for(int i = 0; i < aa.size(); ++i) {
            if(bb[i] >= aa[i])
                     ans.push_back(bb[i] - aa[i]);
            else
                     ans.push_back(bb[i] + 3 - aa[i]);
    }
    while(ans.size() > 1 && ans.back() == 0)
                     ans.pop_back();
    int res = 0;
    int t = 1;
    for(int i = 0; i < ans.size(); ++i) {
            res += t * ans[i];
            t *= 3;
    }
    cout << res;
    cin >> res;
    return 0;
}