#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	vector<string> s = {"H","He","Li","Be","B","C","N","O","F","Ne","Na","Mg","Al","Si","P","S","Cl","Ar","K","Ca","Sc","Ti","V","Cr","Mn","Fe","Co","Ni","Cu","Zn","Ga","Ge","As","Se","Br","Kr","Rb","Sr","Y","Zr","Nb","Mo","Tc","Ru","Rh","Pd","Ag","Cd","In","Sn","Sb","Te","I","Xe","Cs","Ba","La","Hf","Ta","W","Re","Os","Ir","Pt","Au","Hg","Tl","Pb","Bi","Po","At","Rn","Fr","Ra","Ac","Rf","Db","Sg","Bh","Hs","Mt","Ce","Pr","Nd","Pm","Sm","Eu","Gd","Tb","Dy","Ho","Er","Tm","Yb","Lu","Th","Pa","U","Np","Pu","Am","Cm","Bk","Cf","Es","Fm","Md","No","Lr","Rf","Db","Sg","Bh","Hs","Mt","Ds","Rg","Cn","Nh","Fl","Mc","Lv","Ts","Og",};
	for(string& x : s) for(char& c : x) if(c >= 'a' && c <= 'z'){
		c = 'A' + (c - 'a');
	}
	set<string> g;
	for(string x : s) g.insert(x);
	string inp;
	cin >> inp;
	vector<bool> ok(inp.size() + 1, false);
	ok[0] = true;
	for(int i = 1; i < (int)ok.size(); i++){
		for(int j = 0; j < i; j++){
			if(ok[j] && g.count(inp.substr(j, i-j))) ok[i] = true;
		}
	}
	cout << (ok.back() ? "YES" : "NO") << '\n';
}