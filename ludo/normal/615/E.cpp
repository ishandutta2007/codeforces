#include <algorithm>
#include <iostream>

using namespace std;

typedef long long ll;

ll f(ll a)
{
	return a * (3 * a + 2);
}

ll dx[6] = { 1, -1, -2, -1, 1, 2 };
ll dy[6] = { 2, 2, 0, -2, -2, 0};

void run()
{
    ll n;
    cin >> n;
    if (!cin) return;

    ll lo = 0, hi = sqrt((n + 2) / 3) + 1;
    while (hi - lo > 1) {
        ll mid = (lo + hi) / 2;
        if (f(mid) > n) {
            hi = mid;
        } else {
            lo = mid;
        }
    }

    ll layer = lo;
    ll leftOver = n - f(layer);

//	cerr << layer << " " << leftOver << endl;

	ll posx = layer, posy = -2 * layer;
    for (int i = 0; i < 6; i++) {
        ll moves = min(leftOver, layer + (i != 1));

        posx += dx[i] * moves;
        posy += dy[i] * moves;
        leftOver -= moves;
        if (leftOver == 0) {
			break;
        }
    }
    cout << posx << " " << posy << endl;
}

int main()
{
    while(cin) {
        run();
    }
    return 0;
}