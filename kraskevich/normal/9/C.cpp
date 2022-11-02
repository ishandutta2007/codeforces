#include <iostream>
#include <set>
using namespace std;

long long x;
set<long long> s;

void gen(int k, int len, long long res) {
     if(k == len && res <= x && res > 0) 
          s.insert(res);
     if(k < len)
          gen(k + 1, len, res * 10), gen(k + 1, len, res * 10 + 1);
}

int main() {
    cin >> x;
    for(int i = 1; i <= 10; ++i) 
            gen(0, i, 0);
    cout << s.size();
    cin >> x;
    return 0;
}