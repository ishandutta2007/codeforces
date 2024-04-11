#include <iostream>
#include <string>
#include <set>
#include <cstdio>
using namespace std;

#define ll long long
ll p_pow[2000];

void init() {
     p_pow[0] = 1;
     for(int i = 1; i < 2000; ++i)
             p_pow[i] = p_pow[i - 1] * 29;
}

int main() {
    ios_base::sync_with_stdio(0);
    init();
    string patt, sb, se;
    cin >> patt >> sb >> se;
    int pn = patt.length(), nb = sb.length(), ne = se.length();
    ll hb = 0;
    for(int i = 0; i < nb; ++i)
            hb += (sb[i] - 'a' + 1) * p_pow[i];
    ll he = 0;
    for(int i = 0; i < ne; ++i)
            he += (se[i] - 'a' + 1) * p_pow[i];
    he *= p_pow[2000 - ne];
    hb *= p_pow[2000 - nb];
    set<ll> hash[2001];
    ll res = 0;
    ll hp[pn];
    for(int i = 0; i < pn; ++i) {
         hp[i] = (patt[i] - 'a' + 1) * p_pow[i];
         if(i)
              hp[i] += hp[i - 1];
    }   
    for(int i = 0; i < pn; ++i) {
            for(int j = i + max(ne, nb) - 1; j < pn; ++j) {
                    ll al = hp[j] - (i ? hp[i - 1] : 0), l = hp[i + nb - 1] - (i ? hp[i - 1] : 0), r = hp[j] - (j - ne + 1 ?
                            hp[j - ne] : 0);
                    al *= p_pow[1999 - j]; 
                    l *= p_pow[1999 - (i + nb - 1)];
                    r *= p_pow[1999 - j];
                    if(l == hb && r == he && !hash[j - i + 1].count(al)) {
                         ++res;
                         hash[j - i + 1].insert(al);
                    }
            }
    }
    cout << res;
    cin >> nb;
    return 0;
}