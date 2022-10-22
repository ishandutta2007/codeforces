#include <iostream>
using namespace std;

typedef long long ll;

const int Maxn = 40;

ll h, w, sb, hb, pow2[Maxn];

int main()
{
    int i;
    pow2[0] = 1;
    for (i = 1; i < Maxn; i++) pow2[i] = 2*pow2[i-1];
    cin >> h >> w;
    for (i = 0; i < Maxn && pow2[i] <= h; i++) {
        if (ll(5)*pow2[i] < ll(4)*w) {
           if (pow2[i]*(ll(5)*pow2[i]/ll(4)) >= sb) {
                                     sb = pow2[i]*(ll(5)*pow2[i]/ll(4));
                                     hb = pow2[i];
           }
        } else if (ll(4)*pow2[i] <= ll(5)*w && pow2[i]*w >= sb) {
               sb = pow2[i]*w;
               hb = pow2[i];
        }
    }
    for (i = 0; i < Maxn && pow2[i] <= w; i++) {
        if (ll(4)*h > ll(5)*pow2[i]) {
                    if (pow2[i]*(ll(5)*pow2[i]/ll(4)) > sb || 
                        pow2[i]*(ll(5)*pow2[i]/ll(4)) == sb && ll(5)*pow2[i]/ll(4) > hb) {
                                                      sb = pow2[i]*(ll(5)*pow2[i]/ll(4));
                                                      hb = ll(5)*pow2[i]/ll(4);
                    } 
        } else if (ll(5)*h >= pow2[i]*ll(4) && (pow2[i]*h > sb || 
                                                pow2[i]*h == sb && h > hb)) {
                                                          sb = pow2[i]*h;
                                                          hb = h;
        }
    }
    cout << hb << " " << sb/hb << endl;
    return 0;
}