#include <vector>
#include <iostream>
using namespace std;

vector<long long> luck;
long long mx = 0;

void gen(int pos, int len, int cnt4, int cnt7, long long res) {
     if(pos == len) {
            if(cnt7 == cnt4) {
                    mx = res;
                    luck.push_back(res);
            }
            return;
     }
     gen(pos + 1, len, cnt4 + 1, cnt7, res * 10 + 4);
     gen(pos + 1, len, cnt4, cnt7 + 1, res * 10 + 7);
}
                    

int main() {
    int l = 1;
    while(mx < 1e11) {
             gen(0, l, 0, 0, 0);
             ++l;
    }
    long long n;
    
    cin >> n;
    
    int pos = 0;
    
    while(luck[pos] < n)
                    ++pos;
    
   cout << luck[pos];
   
   cin >> n;
   return 0;
}