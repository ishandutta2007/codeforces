#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

const int Maxn = 101;
const int Maxi = 18;
const int Maxj = 1 << 17;

const string nam[Maxn] = {
""
,"H"
,"He"
,"Li"
,"Be"
,"B"
,"C"
,"N"
,"O"
,"F"
,"Ne"
,"Na"
,"Mg"
,"Al"
,"Si"
,"P"
,"S"
,"Cl"
,"Ar"
,"K"
,"Ca"
,"Sc"
,"Ti"
,"V"
,"Cr"
,"Mn"
,"Fe"
,"Co"
,"Ni"
,"Cu"
,"Zn"
,"Ga"
,"Ge"
,"As"
,"Se"
,"Br"
,"Kr"
,"Rb"
,"Sr"
,"Y"
,"Zr"
,"Nb"
,"Mo"
,"Tc"
,"Ru"
,"Rh"
,"Pd"
,"Ag"
,"Cd"
,"In"
,"Sn"
,"Sb"
,"Te"
,"I"
,"Xe"
,"Cs"
,"Ba"
,"La"
,"Ce"
,"Pr"
,"Nd"
,"Pm"
,"Sm"
,"Eu"
,"Gd"
,"Tb"
,"Dy"
,"Ho"
,"Er"
,"Tm"
,"Yb"
,"Lu"
,"Hf"
,"Ta"
,"W"
,"Re"
,"Os"
,"Ir"
,"Pt"
,"Au"
,"Hg"
,"Tl"
,"Pb"
,"Bi"
,"Po"
,"At"
,"Rn"
,"Fr"
,"Ra"
,"Ac"
,"Th"
,"Pa"
,"U"
,"Np"
,"Pu"
,"Am"
,"Cm"
,"Bk"
,"Cf"
,"Es"
,"Fm"
};

int n, k;
string n1[Maxi], n2[Maxi];
int w1[Maxi], w2[Maxi];
vector <int> neigh[Maxn];
bool pos[Maxi][Maxj];
int p[Maxi][Maxj];

int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++) { cin >> n1[i]; w1[i] = find(nam, nam + Maxn, n1[i]) - nam; }
    for (int i = 0; i < k; i++) { cin >> n2[i]; w2[i] = find(nam, nam + Maxn, n2[i]) - nam; }
    for (int mask = 0; mask < 1 << n; mask++) {
        int sum = 0;
        for (int j = 0; j < n; j++) if (mask & 1 << j) sum += w1[j];
        if (sum < Maxn) neigh[sum].push_back(mask);
    }
    pos[0][0] = true;
    for (int i = 0; i < k; i++)
        for (int j = 0; j < 1 << n; j++) if (pos[i][j])
            for (int l = 0; l < neigh[w2[i]].size(); l++) {
                int tr = neigh[w2[i]][l];
                if ((j & tr) == 0 && !pos[i + 1][j | tr]) { pos[i + 1][j | tr] = true; p[i + 1][j | tr] = tr; }
            }
    if (pos[k][(1 << n) - 1]) {
        cout << "YES\n";
        int mask = (1 << n) - 1;
        for (int i = k; i > 0; i--) {
            bool pr = false;
            for (int j = 0; j < n; j++)
                if (p[i][mask] & 1 << j) {
                    if (pr) cout << "+"; pr = true;
                    cout << n1[j];
                }
            cout << "->" << n2[i - 1] << endl;
            mask &= ~p[i][mask];
        }
    } else cout << "NO\n";
    return 0;
}