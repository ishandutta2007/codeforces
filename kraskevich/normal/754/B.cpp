#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int dx[] = {-1, -1, -1,  0,  0,  1,  1,  1};
const int dy[] = {-1,  0,  1, -1,  1, -1,  0,  1};

bool valid(int x, int y) {
    return 0 <= x && x < 4 && 0 <= y && y < 4;
}

bool win(const vector<string>& s) {
    for (int i = 0; i < 4; i++) 
        for (int j = 0; j < 4; j++) {
            for (int d = 0; d < 8; d++) {
                bool ok = true;
                for (int l = 0; l < 3; l++) {
                    int x = i + dx[d] * l;
                    int y = j + dy[d] * l;
                    if (!valid(x, y) || s[x][y] != 'x')
                        ok = false;   
                }
                if (ok)
                    return true;         
            }        
        }    
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); 
    vector<string> s(4);
    for (int i = 0; i < 4; i++)
        cin >> s[i];
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++) 
            if (s[i][j] == '.') {
                s[i][j] = 'x';
                if (win(s)) {
                    cout << "YES" << endl;
                    return 0;
                }
                s[i][j] = 'o';
            }
    cout << "NO" << endl;    
}