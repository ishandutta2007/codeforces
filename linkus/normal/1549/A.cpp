#include <iostream>
#include <map>

int main() {
    int t;
    std::cin >> t;
    while(t--){
        int n;
        std::cin >> n;
        std::map<int,int> mp;
        for(int i = 2; i < n; ++i){
            int cr = n % i;
            if(mp.count(cr)){
                std::cout << mp[cr] << ' ' << i << '\n';
                break;
            }
            mp[cr] = i;
        }
    }
}