#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 1, inf = 1000111222;

bool o1(bool a, bool b) {return a ^ b;}
bool o2(bool a, bool b) {return a & b;}
bool o3(bool a, bool b) {return a | b;}

int main()
{
    //freopen("input.txt", "r", stdin);
    bool a, b, c, d;
    cin >> a >> b >> c >> d;
    bool A = o1(a, b);
    bool B = o3(c, d);
    bool C = o2(b, c);
    bool D = o1(a, d);
    bool I = o2(A, B);
    bool J = o3(C, D);
    cout << o1(I, J) << endl;

    return 0;
}