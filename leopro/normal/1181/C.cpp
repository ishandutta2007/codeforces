#include<vector>
#include<map>
#include<iostream>
#include<set>
#include<string>
#include<algorithm>

using namespace std;

struct Flag{
    int i, j, count;
    int c1, c2, c3;
    Flag(){}
    Flag(int i0, int j0, int c) : i(i0), j(j0), count(c){}
    const bool operator < (const Flag &f) const{
        if (count != f.count) return count < f.count;
        if (i != f.i) return i < f.i;
        if (j != f.j) return j < f.j;
        return false;
    }
    const bool operator == (const Flag &f) const{
        if (i != f.i) return false;
        if (count != f.count) return false;
        
        if (c1 != f.c1) return false;
        if (c2 != f.c2) return false;
        if (c3 != f.c3) return false;
        
        if (abs(j - f.j) == 1) return true;
        return false;
    }
};

vector<Flag> findflags(int j, vector<vector<char>> field){
    vector<int> changes(1, 0);
    for (int i = 1; i < field.size(); ++i){
        if (field[i][j] != field[i - 1][j]) changes.push_back(i);
    }
    changes.push_back(field.size());
    vector<Flag> result;
    for (int i = 3; i < changes.size(); ++i){
        int delta = changes[i - 1] - changes[i - 2];
        if (delta <= changes[i - 2] - changes[i - 3] && delta <= changes[i] - changes[i - 1]){
            int h = changes[i - 2] - (changes[i - 1] - changes[i - 2]);
            result.push_back(Flag(h, j, changes[i - 1] - changes[i - 2]));
        }
    }
    return result;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<char>> field(n, vector<char>(m, 0));
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            cin >> field[i][j];
        }
    }
    vector<Flag> flags;
    for (int j = 0; j < m; ++j){
        vector<Flag> f = findflags(j, field);
        for (Flag t: f){
            flags.push_back(t);
        }
    }
    for (int i = 0; i < flags.size(); ++i){
        flags[i].c1 = field[flags[i].i + flags[i].count * 0][flags[i].j];
        flags[i].c2 = field[flags[i].i + flags[i].count * 1][flags[i].j];
        flags[i].c3 = field[flags[i].i + flags[i].count * 2][flags[i].j];
    }
    stable_sort(flags.begin(), flags.end());
    long long ans = 0;
    for (int i = 0; i < flags.size(); ++i){
        long long count = 1;
        for (++i; i < flags.size() && flags[i] == flags[i - 1]; ++i) {
            if (flags[i] == flags[i - 1]) ++count;
        }
        --i;
        ans += count * (count + 1);
        
    }
    cout << ans / 2 << endl;
}