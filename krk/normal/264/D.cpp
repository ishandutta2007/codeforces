#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;

const int Maxn = 1000005;
const string RBG = "RBG";
const int Maxm = 3;
 
string A;
string B;
ll res;
int sum[Maxn][Maxm][Maxm];
 
int main()
{
    cin >> A;
    cin >> B;
    for (int i = 1; i < B.length(); i++) {
        for (int a = 0; a < Maxm; a++)
            for (int b = 0; b < Maxm; b++)
                sum[i][a][b] = sum[i - 1][a][b];
        sum[i][RBG.find(B[i - 1])][RBG.find(B[i])]++;
    }
    int lef = 0, rig = 0;
    for (int i = 0; i < A.length(); i++) {
        int sub = 0;
        if (i && A[i] != A[i - 1])
            sub = sum[rig][RBG.find(A[i])][RBG.find(A[i - 1])] - sum[lef][RBG.find(A[i])][RBG.find(A[i - 1])];
        while (rig + 1 < B.length() && B[rig] != A[i]) rig++;
        if (lef > rig) break;
        res += rig - lef + 1 - sub;
        if (rig + 1 < B.length() && B[rig] == A[i]) rig++;
        if (lef < B.length() && B[lef] == A[i]) lef++;
    }
    cout << res << endl;
    return 0;
}