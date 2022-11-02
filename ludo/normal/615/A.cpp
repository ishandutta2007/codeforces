#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n, m, x, y;
    cin >> n >> m;
    vector<bool> v(m + 1);
    while (n--) {
		cin >> x;
		while (x--) {
			cin >> y;
			v[y] = true;
		}
    }

    bool ret = true;
    for (int i = 1; i <= m; i++) {
		ret &= v[i];
    }
    cout << (ret ? "YES" : "NO") << endl;
    return 0;
}