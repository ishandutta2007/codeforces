#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    vector<int> sum(2, 0);
    vector<string> str(1);
    
    int n;
    
    cin >> n;
    
    cin >> str[0];
    sum[0]++;
    for(int i = 1; i < n; ++i) {
            string cur;
            cin >> cur;
            if(cur == str[0])
                          sum[0]++;
            else {
                 sum[1]++;
                 if(str.size() != 2)
                               str.push_back(cur);
            }
    }
    
    if(sum[0] > sum[1])
              cout << str[0];
    else
        cout << str[1];
        
    return 0;
}