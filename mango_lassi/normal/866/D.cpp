#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

const int N = 1<<19;
const int inf = 1e9 + 7;
int min [2*N];
int add [2*N];
int high;


void add_interval(int s, int e, int d, int i = 1, int cs = 0, int ce = high) {
	//std::cout << "add_interval " << s << ' ' << e << ' ' << d << ' ' << i << ' ' << cs << ' ' << ce << '\n';
	if ((ce < s) || (e < cs)) return;
	if ((s <= cs) && (ce <= e)) {
		add[i] += d;
		min[i] += d;
	} else {
		int mid = (cs + ce) / 2;
		add_interval(s,e,d,2*i  ,cs   ,mid);
		add_interval(s,e,d,2*i+1,mid+1,ce );
		min[i] = std::min(min[2*i], min[2*i+1]) + add[i];
	}
}

int get_min(int s, int e, int i = 1, int cs = 0, int ce = high) {
	// std::cout << "get_min " << s << ' ' << e << ' ' << ' ' << i << ' ' << cs << ' ' << ce << '\n';
	if (e < s) return inf;
	if ((ce < s) || (e < cs)) return inf;
	if ((s <= cs) && (ce <= e)) return min[i];
	int mid = (cs + ce) / 2;
	return std::min(get_min(s,e,2*i,cs,mid), get_min(s,e,2*i+1,mid+1,ce)) + add[i];
}

void print(int i = 1, int cs = 0, int ce = high) {
	std::cout << cs << ' ' << ce << " min add " << min[i] << ' ' << add[i] << '\n';
	if (cs != ce) {
		int mid = (cs + ce) / 2;
		print(2*i, cs, mid);
		print(2*i+1, mid+1, ce);
	}
}

int main() {
	int n;
	std::cin >> n;

	high = 1;
	while(high < n) high <<= 1;
	--high;

	for (int i = 1; i < n; ++i) {
		add_interval(i, n-1, 1);
	}

	long long total = 0;
	std::vector<std::pair<int, int>> days;
	for (int i = 0; i < n; ++i) {
		int price;
		std::cin >> price;
		days.push_back({-price, i});
	}
	std::sort(days.begin(), days.end());
	for (int i = 0; i < days.size(); ++i) {
		// if(i == 1) print();
		int price = -days[i].first;
		int ind = days[i].second;
		int after = get_min(ind+1, n-1);
		int val = get_min(ind, ind);
		//std::cout << i << ' ' << price << ' ' << ind << ' ' << after << ' ' << val << ' ';
		if ((after >= 2) && (val >= 1)) {
			//std::cout << "sell\n";
			add_interval(ind+1, n-1, -2);
			add_interval(ind, ind, -1);
			total += price;
		} else if (after > 0) {
			//std::cout << "skip\n";
			add_interval(ind+1, n-1, -1);
		} else {
			//std::cout << "buy\n";
			total -= price;
		}
		//print();
	}
	std::cout << total << '\n';
}