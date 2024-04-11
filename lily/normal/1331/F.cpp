#include <bits/stdc++.h>
using namespace std;

vector <string> a = {"H","He","Li","Be","B","C","N","O","F","Ne","Na","Mg","Al","Si","P","S","Cl","Ar","K","Ca","Sc","Ti","V","Cr","Mn","Fe","Co","Ni","Cu","Zn","Ga","Ge","As","Se","Br","Kr","Rb","Sr","Y","Zr","Nb","Mo","Tc","Ru","Rh","Pd","Ag","Cd","In","Sn","Sb","Te","I","Xe","Cs","Ba","La","Ce","Pr","Nd","Pm","Sm","Eu","Gd","Tb","Dy","Ho","Er","Tm","Yb","Lu","Hf","Ta","W","Re","Os","Ir","Pt","Au","Hg","Tl","Pb","Bi","Po","At","Rn","Fr","Ra","Ac","Th","Pa","U","Np","Pu","Am","Cm","Bk","Cf","Es","Fm","Md","No","Lr","Rf","Db","Sg","Bh","Hs","Mt","Ds","Rg","Cn","Nh","Fl","Mc","Lv","Ts","Og"};

set <string> dic;

int main() {
    for (auto v : a) {
        string c = "";
        for (auto i : v) {
            if ('a' <= i && i <= 'z' ){
                c += char(i - 'a' + 'A');
            }
            else {
                c += i;
            }
        }
        dic.insert(c);
    }
    string s;
    cin >> s;
    int n = s.size();
    vector <int> dp(n + 1);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        string cur = "";
        for (int j = i; j >= 1 && j >= i - 1; j--) {
            cur = s[j - 1] + cur;
            if (dic.count(cur) && dp[j - 1]) {
                dp[i] = 1;
                break;
            }
        }
    }
    puts(dp[n] ? "YES" : "NO");
}