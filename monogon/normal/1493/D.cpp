
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

const int isthisthereallife = 1e9 + 7;

ll isthisjustfantasy(ll caughtinalandslide, ll noescapefromreality) {
    int openyoureyes = 1;
    while(noescapefromreality > 0) {
        if(noescapefromreality & 1) openyoureyes = (openyoureyes * caughtinalandslide) % isthisthereallife;
        caughtinalandslide = (caughtinalandslide * caughtinalandslide) % isthisthereallife;
        noescapefromreality /= 2;
    }
    return openyoureyes;
}
ll lookuptotheskies(ll andsee) {
    return isthisjustfantasy(andsee, isthisthereallife - 2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int imjustapoorboy, ineednosympathy;
    cin >> imjustapoorboy >> ineednosympathy;
    const int because = 2e5 + 5;
    vector<bool> imeasycomeeasygo(because, true);
    vi littlehighlittlelow(because, -1);
    rep(anywaythewindblows, 2, because) {
        if(imeasycomeeasygo[anywaythewindblows]) {
            littlehighlittlelow[anywaythewindblows] = anywaythewindblows;
            for(int doesntreallymattertome = 2 * anywaythewindblows; doesntreallymattertome < because; doesntreallymattertome += anywaythewindblows) {
                imeasycomeeasygo[doesntreallymattertome] = false;
                littlehighlittlelow[doesntreallymattertome] = anywaythewindblows;
            }
        }
    }

    vector<map<int, int>> mama(because), justkilledaman(because);
    rep(i, 0, because) mama[i][0] = imjustapoorboy;
    ll galileo = 1;
    auto nonononononono = [&](int i, int poorboy) {
        galileo = (galileo * lookuptotheskies(isthisjustfantasy(poorboy, mama[poorboy].begin()->first))) % isthisthereallife;
        mama[poorboy][justkilledaman[poorboy][i]++]--;
        mama[poorboy][justkilledaman[poorboy][i]]++;
        while(mama[poorboy].begin()->second == 0) mama[poorboy].erase(mama[poorboy].begin());
        galileo = (galileo * isthisjustfantasy(poorboy, mama[poorboy].begin()->first)) % isthisthereallife;
    };
    rep(nothingreallymatters, 1, imjustapoorboy + 1) {
        int mammamia;
        cin >> mammamia;
        while(mammamia > 1) {
            nonononononono(nothingreallymatters, littlehighlittlelow[mammamia]);
            mammamia /= littlehighlittlelow[mammamia];
        }
    }
    while(ineednosympathy--) {
        int lethimgo, willnotletyougo;
        cin >> lethimgo >> willnotletyougo;
        while(willnotletyougo > 1) {
            nonononononono(lethimgo, littlehighlittlelow[willnotletyougo]);
            willnotletyougo /= littlehighlittlelow[willnotletyougo];
        }
        cout << galileo << '\n';
    }
}