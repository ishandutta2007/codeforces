#include<vector>
#include<map>
#include<iostream>
#include<set>
#include<string>

// void solve(){
//     string s;
//     cin >> s;
//     n = s.size();
//     set<char> letters;
//     for (int i = 0; i < n; ++i){
//         letters.insert(s[i]);
//     }
//     vector<char> L;
//     for (char c: letters){
//         L.push_back(c);
//     }
    
// }

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<bool> put(n);
    for (int i = 0; i < n; ++i){
        char x;
        cin >> x;
        put[i] = (x == '+');
    }
    int heap = n * 2;
    int min = heap;
    for (int i = 0; i < n; ++i){
        if (put[i]) heap++; else heap--;
        if(min > heap) min = heap;
    }
    for (int i = 0; i < n; ++i){
        if (put[i]) heap--; else heap++;
    }
    heap -= min;
    for (int i = 0; i < n; ++i){
        if (put[i]) heap++; else heap--;
    }
    cout << (heap) << endl;
}