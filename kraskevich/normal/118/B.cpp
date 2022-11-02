#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    int maxL = (2 * n + 1) * 2 - 1;
    
    for(int i = 0; i <= n; ++i) {
            int curL = (maxL - (2 * (2 * i + 1) - 1)) / 2;
            for(int j = 0; j < curL; ++j)
                    cout << " ";
            for(int j = 0; j < i; ++j)
                    cout << j << " ";
            if(i)
                 cout << i << " ";
            for(int j = i - 1; j > 0; --j)
                    cout << j << " ";
            cout << 0 << endl;
    }
     for(int i = n - 1; i >= 0; --i) {
            int curL = (maxL - (2 * (2 * i + 1) - 1)) / 2;
            for(int j = 0; j < curL; ++j)
                    cout << " ";
            for(int j = 0; j < i; ++j)
                    cout << j << " ";
            if(i)
                 cout << i << " ";
            for(int j = i - 1; j > 0; --j)
                    cout << j << " ";                   
            cout << 0 << endl;
    }
    
    cin >> n;
    
    return 0;
}