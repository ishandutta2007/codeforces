#include <iostream>
#include <vector>

int x, y;

bool ask (std::vector<int>& indexes) {
	std::cout << "? " << indexes.size();
	for (int i = 0; i < indexes.size(); ++i) {
		std::cout << ' ' << (indexes[i] + 1);
	}
	std::cout << std::endl;
	int ans;
	std::cin >> ans;
	if (indexes.size() & 1) {
		ans ^= x;
	}
	bool res = (ans != 0);
	return res;
}

int find_mid(int n) {
	int mid = 1;
	while(mid * 2 < n) {
		mid *= 2;
	}
	return mid;
}

// Find all nodes on a certain level of questions
std::vector<int> level (int i, int n) {
	int mid = find_mid(n);
	if ( (i == 0) || (n == 1) ) {
		std::vector<int> res (mid);
		for (int j = 0; j < mid; ++j) {
			res[j] = j;
		}
		return res;
	} else {
		std::vector<int> left = level(i-1, mid);
		std::vector<int> right = level(i-1, n-mid);
		for (int j = 0; j < right.size(); ++j) {
			left.push_back(right[j] + mid);
		}
		return left;
	}
}

int search(std::vector<int>& indexes) {
	//std::cout << "SEARCHING!\n";
	int low = 0;
	int high = indexes.size() - 1;
	while(low != high) {
		int mid = find_mid(high - low + 1) + low;
		std::vector<int> question (mid - low);
		for (int i = low; i < mid; ++i) {
			question[i-low] = indexes[i];
		}
		if (ask(question)) {
			high = mid - 1;
		} else {
			low = mid;
		}
	}
	//std::cout << "FOUND " << indexes[low] << '\n';
	return indexes[low];
}

void ind_to_path(std::vector<bool>& path, int ind, int n, int i = 0) {
	if (n == 1) return;
	int mid = find_mid(n);
	if (ind < mid) {
		path[i] = true;
		ind_to_path(path, ind, mid, i+1);
	} else {
		path[i] = false;
		ind_to_path(path, ind-mid, n-mid, i+1);
	}
}

void path_to_ind(std::vector<bool> path, int& ind, int n, int i = 0) {
	if (n == 1) return;
	int mid = find_mid(n);
	if (path[i]) {
		path_to_ind(path, ind, mid, i+1);
	} else {
		ind += mid;
		path_to_ind(path, ind, n-mid, i+1);
	}
}

int main() {
	// Interactive problem, these are not necessary
	// std::ios_base::sync_with_stdio(false);
	// std::cin.tie(0);
	int n;
	std::cin >> n >> x >> y;
	int depth = 0;
	int temp = 1;
	while(temp < n) {
		++depth;
		temp *= 2;
	}
	std::vector<bool> answers;
	int one = -1;
	for (int i = 0; i < depth; ++i) {
		std::vector<int> question = level(i, n);
		if (ask(question)) {
			answers.push_back(true);
			if (one == -1) {
				one = search(question);
			}
		} else {
			answers.push_back(false);
		}
	}
	std::vector<bool> path (depth);
	ind_to_path(path, one, n);
	for (int i = 0; i < depth; ++i) {
		path[i] = path[i] ^ answers[i];
	}
	int other = 0;
	path_to_ind(path, other, n);
	std::cout << "! " << (one+1) << ' ' << (other+1) << '\n';
}