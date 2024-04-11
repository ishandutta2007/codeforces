#include <algorithm>
#include <cassert>
#include <iostream>
int n, q[6][6][6], idx[6], l1, l2, l3, res[1001];

int count_query = 0;
int query(int a, int b, int c)
{
	// assert(++count_query <= n * 4 && a <= n && b <= n && c <= n);
	std::cout << "? " << a << " " << b << " " << c << std::endl;
	int res; std::cin >> res;
	return res;
}

int get_query(int a, int b, int c) 
{ 
	int x = std::min(a, std::min(b, c));
	int z = std::max(a, std::max(b, c));
	int y = a + b + c - x - z;
	return q[x][y][z]; 
}

int get_idx_query(int a, int b, int c) 
{ 
	return get_query(idx[a], idx[b], idx[c]); 
}

void init()
{
	for (int i = 0 + 1; i <= 5; ++i)
		for (int j = i + 1; j <= 5; ++j)
			for (int k = j + 1; k <= 5; ++k)
				q[i][j][k] = query(i, j, k);
	for (int i = 1; i <= 5; ++i)
		idx[i] = i;
	std::sort(idx + 1, idx + 5 + 1, [](int a, int b){
		for (int i = 1; i <= 5; ++i)
			for (int j = 1; j <= 5; ++j)
				if (i != a && i != b && j != a && j != b && i != j)
				{
					int x = get_query(a, i, j);
					int y = get_query(b, i, j);
					if (x > y)
						return false;
				}
		for (int i = 1; i <= 5; ++i)
			for (int j = 1; j <= 5; ++j)
				if (i != a && i != b && j != a && j != b && i != j)
				{
					int x = get_query(a, i, j);
					int y = get_query(b, i, j);
					if (x < y)
						return true;
				}
		return false;
	});
	int a = get_idx_query(1, 2, 3),
	    b = get_idx_query(1, 2, 4),
	    c = get_idx_query(1, 3, 5),
	    d = get_idx_query(2, 4, 5),
	    e = get_idx_query(3, 4, 5);
	res[idx[1]] = (a + c - e) / 2;
	res[idx[3]] = (e + a - c) / 2;
	res[idx[5]] = (c + e - a) / 2;
	res[idx[2]] = d - res[idx[5]];
	res[idx[4]] = b - res[idx[1]];
	l1 = idx[1];
	l2 = idx[2];
	l3 = idx[3];
}

int main()
{
	std::cin >> n;
	init();
	for (int i = 6; i <= n; ++i)
	{
		int x = query(l1, l2, i);
		if (x < res[l1] + res[l2])
		{
			res[i] = x - res[l2];
			l2 = l1;
			l1 = i;
			continue;
		}
		if (x == res[l1] + res[l2])
		{
			res[i] = query(l2, l3, i) - res[l3];
			l2 = i;
			continue;
		}
		if (x > res[l1] + res[l2])
		{
			res[i] = x - res[l1];
			continue;
		}
	}
	std::cout << '!';
	for (int i = 1; i <= n; ++i)
		std::cout << ' ' << res[i];
	std::cout << std::endl;
	return 0;
}