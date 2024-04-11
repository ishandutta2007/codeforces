#include <iostream>

using namespace std;

typedef long long int64;

const int maxn = /*20;//*/ 100010;
const int size = /*3; //*/ 318;
const int blocks = maxn / size + 1;

int data[blocks][size], tmp[size];
int total[blocks][maxn];
int delta[blocks];

void update(int b){
	for (int i = 0, p = size - delta[b]; i < size; ++i, ++p){
		if (p == size) p = 0;
		tmp[i] = data[b][p];
	}
	delta[b] = 0;
	for (int i = 0; i < size; ++i)
		data[b][i] = tmp[i];
}

int push(int b, int v){
	delta[b]++;
	int ans = data[b][size - delta[b]];
	data[b][size - delta[b]] = v;
	if (delta[b] == size) delta[b] = 0;

	total[b][v]++;
	total[b][ans]--;

	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;

	int cb = 0, cp = 0;
	for (int i = 0; i < n; ++i, ++cp){
		if (cp == size){
			cp = 0;
			++cb;
		}
		cin >> data[cb][cp];
		total[cb][data[cb][cp]]++;
	}

	int lastans = 0;
	int q; cin >> q;

	while (q--){
		int m; cin >> m;
		if (m == 1){
			int l, r; cin >> l >> r;
			l = (l + lastans - 1 + n) % n; // + 1
			r = (r + lastans - 1 + n) % n; // + 1
			if (l > r) swap(l, r);

			int lb = l / size, lp = l % size;
			int rb = r / size, rp = r % size;

			if (lb == rb){
				update(lb);
				int tmp = data[lb][rp];
				for (int i = rp; i > lp; --i)
					data[lb][i] = data[lb][i - 1];
				data[lb][lp] = tmp;
			}
			else{
				update(lb); update(rb);

				int t = data[lb][size - 1];
				total[lb][t]--;

				for (int i = lb + 1; i < rb; ++i)
					t = push(i, t);

				int tmp = data[rb][rp];
				for (int i = rp; i; --i)
					data[rb][i] = data[rb][i - 1];
				data[rb][0] = t;

				total[rb][tmp]--;
				total[rb][t]++;

				total[lb][tmp]++;
				for (int i = size - 1; i > lp; --i)
					data[lb][i] = data[lb][i - 1];
				data[lb][lp] = tmp;
			}
			/*cout << l << " " << r << endl;
			cout << "view: ";
			int b = 0, p = 0;
			update(0);
			for (int i = 0; i < n; ++i, ++p){
				if (p == size){
					p = 0, ++b;
					update(b);
				}
				cout << data[b][p] << " ";
			}
			cout << endl;*/
		}
		else{
			int l, r, k;
			cin >> l >> r >> k;
			l = (l + lastans - 1 + n) % n; // + 1
			r = (r + lastans - 1 + n) % n; // + 1
			k = (k + lastans - 1 + n) % n + 1;
			if (l > r) swap(l, r);

			int lb = l / size, lp = l % size;
			int rb = r / size, rp = r % size;

			int ans = 0;
			if (lb == rb){
				update(lb);
				for (int i = lp; i <= rp; ++i)
				if (data[lb][i] == k) ++ans;
			}
			else{
				update(lb); update(rb);
				for (int i = lp; i < size; ++i)
					if (data[lb][i] == k) ++ans;
				for (int i = 0; i <= rp; ++i)
					if (data[rb][i] == k) ++ans;
				for (int i = lb + 1; i < rb; ++i)
					ans += total[i][k];
			}

			cout << ans << endl;
			lastans = ans;
		}
	}

	return 0;
}