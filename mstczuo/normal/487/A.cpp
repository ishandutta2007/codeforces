# include <iostream>
# include <cstdio>
# include <cstring>

using namespace std;

int Hy, Ay, Dy, Hm, Am, Dm;
int h, a, d, cost;

int main() {
    cin >> Hy >> Ay >> Dy;
    cin >> Hm >> Am >> Dm;
    cin >> h >> a >> d;
    int ans = ~0U>>1;
    for(int i = 0; ; ++i) {
        // buy attack of Yang
        int da = (Ay + i - Dm);
        if(da <= 0) continue;
        int day = (Hm + da - 1) / da;
        for(int j = 0; ; ++j) {
            // buy defense of Yang
            cost = a * i + d * j;
            int db = (Am - Dy - j);
            if(db <= 0) {
                ans = min(ans, cost);
                break;
            }
            int hps = day * db + 1;
            if(Hy < hps) cost += h * (hps - Hy);
            ans = min(ans, cost);
        }
        if(day == 1) break;
    }
    cout << ans << endl;
}