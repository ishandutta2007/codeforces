#include <iostream>

using namespace std;

int q;

int main(void)
{
	cin >> q;
	int l, r, L, R;
	for(int i = 0; i < q; i++){
		cin >> l >> r >> L >> R;
		if(l < L) cout << l << " " << R << endl;
		else cout << r << " " << L << endl;
	}
	return 0;
}