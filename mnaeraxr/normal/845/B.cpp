#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100000 + 10;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s; cin >> s;

    vector<int> value(6);

    for (int i = 0; i < 6; ++i)
        value[i] = s[i] - '0';


    int A = value[0] + value[1] + value[2];
    int B = value[3] + value[4] + value[5];

    if (A < B){
        for (int i = 0; i < 3; ++i)
            swap(value[i], value[i + 3]);
        swap(A, B);
    }

    int answer = 0;

    while (A > B){
        answer += 1;
        int a = -1, pa = -1;
        for (int i = 0; i < 3; ++i){
            if (value[i] > a){
                a = value[i];
                pa = i;
            }
        }

        int b = 10, pb = -1;
        for (int i = 0; i < 3; ++i){
            if (value[i + 3] < b){
                b = value[i + 3];
                pb = i + 3;
            }
        }

        int sa = a, sb = 9 - b;

        if (sa > sb){
            A -= sa;
            value[pa] = 0;
        }
        else{
            B += sb;
            value[pb] = 9;
        }
    }

    cout << answer << endl;

    return 0;
}