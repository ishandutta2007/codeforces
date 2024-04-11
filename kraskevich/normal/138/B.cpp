#include <algorithm>
#include <iostream>
#include <string.h>
#include <sstream>
#include <fstream>
#include <cassert>
#include <cstdlib>
#include <complex>
#include <cctype>
#include <cstdio>
#include <vector>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

const int INF = 1000;
int best = -1;
string A, B;
string ansA;
string ansB;

int main()
{
    ios_base::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    string s;
    cin >> s;
    int n = s.length();
    vector<int> cnt1(10, 0);
    vector<int> cnt2(10, 0);
    for (int i = 0; i < n; i++)
        cnt1[s[i] - '0']++;
    cnt2 = cnt1;
    vector<int> p1 = cnt1;
    vector<int> p2 = cnt2;
    for (int D = 1; D <= 9; D++)
    {
        cnt1 = p1;
        cnt2 = p2;
        A = "";
        B = "";
        if (cnt1[D] && cnt2[10 - D])
        {
            cnt1[D]--;
            cnt2[10 - D]--;
            A += char('0' + D);
            B += char('0' + 10 - D);
        }
        for (int d = 0; d <= 9; d++)
        {
            int rep = min(cnt1[d], cnt2[9 - d]);
            cnt1[d] -= rep;
            cnt2[9 - d] -= rep;
            for (int i = 0; i < rep; i++)
                A += char(d + '0'), B += char(9 - d + '0');
        }
        string a, b;
        for (int i = 0; i < min(cnt2[0], cnt1[0]); i++)
            a += '0', b += '0';
        A = a + A;
        B = b + B;
        int d = min(cnt1[0], cnt2[0]);
        cnt1[0] -= d;
        cnt2[0] -= d;
        for (int d = 0; d < 10; d++)
            for (int i = 0; i < cnt1[d]; i++)
                A += char('0' + d);
        for (int d = 0; d < 10; d++)
            for (int i = 0; i < cnt2[d]; i++)
                B += char('0' + d);
        reverse(A.begin(), A.end());
        reverse(B.begin(), B.end());
        //cerr << A << " " << B << endl;
        int cur = 0;
        int carry = 0;
        for (int i = n - 1; i >= 0; --i)
        {
            int sum = carry + A[i] - '0' + B[i] - '0';
            if (sum % 10 == 0)
                cur++;
            else
                break;
            carry = sum / 10;
        }
        //cerr << cur << endl;
        if (cur > best)
        {
            best = cur;
            ansA = A;
            ansB = B;
        }
    }

    cout << ansA << endl << ansB;

    return 0;
}