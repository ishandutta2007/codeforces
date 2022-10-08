#include <iostream>
#include <algorithm>

struct Dragon {
public:
	Dragon() : strength(0), bonus(0) {}
	Dragon(int s, int b) : strength(s), bonus(b) {}
	int strength;
	int bonus;
};

bool compare(Dragon a, Dragon b) {
	return a.strength < b.strength;
}

int s, n;
Dragon dragons[1000];
int x, y;
bool possible = true;

int main() {
	std::cin >> s >> n;
	for(int i = 0; i < n; i++) {
		std::cin >> x >> y;
		dragons[i] = Dragon(x, y);
	}
	std::sort(dragons, dragons + n, compare);
	for(int i = 0; i < n; i++) {
		if(s > dragons[i].strength)
			s += dragons[i].bonus;
		else {
			possible = false;
			break;
		}
	}
	std::cout << (possible ? "YES" : "NO");
}