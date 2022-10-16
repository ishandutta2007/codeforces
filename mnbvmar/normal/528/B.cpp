#include <bits/stdc++.h>

typedef long long LL;

using namespace std;


const int MaxN = 200005;

struct Interval {
	int left, right;

	bool operator<(const Interval& other) const {
		return right < other.right;
	}
};

Interval pts[MaxN];
int N;

void input(){
	scanf("%d", &N);
	for(int i = 0; i < N; i++){
		int x, w;
		scanf("%d%d", &x, &w);
		pts[i] = Interval{x-w, x+w};
	}
}

int main(){
	input();

	sort(pts, pts+N);

	int result = 0, maxRange = -2e9;

	for(int i = 0; i < N; i++){
//		printf("%d %d %d\n", pts[i].left, pts[i].right, maxRange);
		if(pts[i].left >= maxRange){
			result++;
			maxRange = pts[i].right;
		}
	}

	printf("%d\n", result);
}