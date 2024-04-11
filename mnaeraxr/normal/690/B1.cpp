#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100010;

void check(char a, char b){
    if (a != b){
        cout << "No" << endl;
        exit(0);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vector<string> mat(n);

    int x1 = -1, y1, x2, y2;

    for (int i = 0; i < n; ++i){
        cin >> mat[i];

        for (int j = 0; j < n; ++j){
            if (mat[i][j] == '4'){
                if (x1 == -1){
                    x1 = x2 = i;
                    y1 = y2 = j;
                }
                else{
                    x1 = min(x1, i);
                    x2 = max(x2, i);
                    y1 = min(y1, j);
                    y2 = max(y2, j);
                }
            }
        }
    }


    if (x1 == -1) cout << "No" << endl;
    else{
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j){

                if (i == x1 - 1 && j == y1 - 1) check(mat[i][j], '1');
                else if (i == x2 + 1 && j == y1 - 1) check(mat[i][j], '1');
                else if (i == x1 - 1 && j == y2 + 1) check(mat[i][j], '1');
                else if (i == x2 + 1 && j == y2 + 1) check(mat[i][j], '1');

                else if (i == x1 - 1 && y1 <= j && j <= y2) check(mat[i][j], '2');
                else if (i == x2 + 1 && y1 <= j && j <= y2) check(mat[i][j], '2');
                else if (j == y1 - 1 && x1 <= i && i <= x2) check(mat[i][j], '2');
                else if (j == y2 + 1 && x1 <= i && i <= x2) check(mat[i][j], '2');

                else if (x1 <= i && i <= x2 && y1 <= j && j <= y2) check(mat[i][j], '4');
                else check(mat[i][j], '0');
            }

        cout << "Yes" << endl;
    }



    return 0;
}