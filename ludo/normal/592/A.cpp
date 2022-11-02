#include<cassert>
#include<iostream>
#include<cstdio>

using namespace std;

char b[8][8];
int minStepW, minStepB;

int main()
{
#ifdef LOCAL
    assert(freopen("input.txt", "r", stdin));
#endif // LOCAL

    for(int r = 0; r < 8; r++) {
        for(int c = 0; c < 8; c++) {
            cin >> b[r][c];
        }
    }

    minStepW = minStepB = 1000;

    for(int c = 0; c < 8; c++) {
        for(int r = 0; r < 8; r++) {
            if(b[r][c] == 'B') {
                break;
            } else if(b[r][c] == 'W') {
                minStepW = min(minStepW, r);
                break;
            }
        }
        for (int r = 8; r--; ) {
            if (b[r][c] == 'W') {
                break;
            } else if (b[r][c] == 'B') {
                minStepB = min(minStepB, 7 - r);
                break;
            }
        }
    }

    cout << ((minStepW <= minStepB) ? "A" : "B") << endl;
    return 0;
}