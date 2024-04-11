#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
#include <cmath>
#include <bitset>
#include <deque>
#include <map>
#include <iomanip>

using namespace std;

const int CMax = 200002;
const int CInf = 2000000001;
const long long CMod = 1000000007;

int t, n, k;
long long res[CMax];
string S;
set < pair <int, int> > A, D;
set < pair <int, int> >::reverse_iterator ait, dit;

int gcd(int a, int b)
{
    if (b != 0) return gcd(b, a % b);
    else return a;
}

string baseConverter(int base, int num) {
    string tNum = "";
    while (num > 0) {
        tNum = (char)('0' + num%base) + tNum;
        num /= base;
    }
}

bool isPalindrom(string tS) {
    int sn = (int)tS.length();
    for (int i = 0; i < sn / 2; i++) {
        if (tS[i] != tS[sn - i - 1]) return false;
    }
    return true;
}

int dist(int i, int j) {
    return  (j < i ? n + j : j) - i;
}

long long greatestDivisor(long long a) {
    for (int i = 2; i <= (long long)sqrt(a); i++) {
        if (a % i == 0) return a / i;
    }
    return a;
}
/*
bool isSorted(int l, int k) {
    for (int i = l+1; i < l+k; i++) {
        if (A[i] < A[i-1]) return false;
    }
    return true;
}
*/

int numSum(int c){
    int tDg, sum = 0;
    while (c > 0) {
        sum += c % 10;
        c /= 10;
    }
    return sum;
}

int main()
{
    scanf("%d %d", &n, &k);
    int u, v;
    long long currS = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &u);
        A.insert(make_pair(u, i));
    }
    for (int i = 0; i < k; i++) {
        scanf("%d %d", &u, &v);
        D.insert(make_pair(u, v));
        currS += (long long)v;
    }


    pair <int, int> tA, tD;

    dit = D.rbegin();
    tD = *dit;

    for (ait = A.rbegin(); ait != A.rend() && dit != D.rend(); ++ait) {
        tA = *ait;
        while (tA.first < tD.first && dit != D.rend()) {
            currS -= (long long)tD.second;
            ++dit;
            tD = *dit;
        }
        res[tA.second] = currS;
    }

    for (int i = 0; i < n; i++) {
        printf("%I64d ", res[i]);
    }
    printf("\n");

    return 0;
}