#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <assert.h>
#include <algorithm>
#include <random>
#include <string>

#define endl '\n'

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s; cin >> s;

    s = "$" + s;

    map<char,long long> freq;
    map<string,long long> hidden;

    for (auto x : s) {
        for (auto u : freq) {
            string r; r += u.first; r += x;
            hidden[r] += u.second;
        }
        freq[x]++;
    }

    long long answer = 0;

    for (auto x : hidden){
        // cout << x.first << " " << x.second << endl;
        answer = max(answer, x.second);
    }

    cout << answer << endl;

    return 0;
}