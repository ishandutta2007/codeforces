#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = a; i < b; ++i)
#define OUT(x) {cout << x; exit(0); }

string res;
void conv(int i, int j) {
    res += ' ';
    res += (char)(j - 1 + 'a');
    res += (char)(i + '0');
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	res = "a1";
	int n;
	cin >> n;

	int i = 1, j = 1;

	while (n > 2) {
        if (i == 7 && j == 6 && n == 3) {
            conv(7, 7); conv(7, 8); conv(8, 8);
            OUT(res);
        }
        else if (i == 7 && j == 6) j = 8;
        else if (i == 7 && j == 8) --j;
        else if (i == 7 && j == 7) ++i;
        else if (i == 8)--j;
        else if (i % 2 ==1) {
            if (j == 8) ++i;
            else ++j;
        }
        else {
            if (j == 1)++i;
            else --j;
        }

        conv(i, j);
        --n;
	}

    if (j == 8) conv(i+1, 8), conv(8, 8);
	else if (i < 8) conv(8, j), conv(8, 8);
	else conv(i, j-1), conv(8, 8);

	cout << res;
}