#include <cassert>
#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
//#ifdef LOCAL
//	freopen("input.txt", "r", stdin);
//#endif // LOCAL

	int n, m1, m2, m3, n1, n2, n3;
    cin >> n >> m1 >> n1 >> m2 >> n2 >> m3 >> n3;

	int s = m1 + m2 + m3;

	while (s < n) {
		if (m1 < n1) m1++;
		else if (m2 < n2) m2++;
		else if (m3 < n3) m3++;
		else assert(false);

		s++;
	}
	cout << m1 << " " << m2 << " " << m3 << endl;
    return 0;
}