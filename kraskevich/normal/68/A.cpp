#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int p[4], a, b, res = 0;
    
    for(int i = 0; i < 4; ++i)
            cin >> p[i];
    cin >> a >> b;
    
    sort(p, p + 4);
    
    int f[b + 1];
    for(int i = 0; i <= b; ++i)
            f[i] = 0;
            
    for(int i = 0; i < 22; ++i)
            for(int j = a; j <= b; ++j)
                    if(j % p[0] % p[1] % p[2] % p[3] == j)
                         ++f[j];
            next_permutation(p, p + 4);
    for(int i = a; i <= b; ++i)
            if(f[i] >= 7)
                    ++res;
                    
    cout << res << endl;
    
    cin >> a;
    
    return 0;
}