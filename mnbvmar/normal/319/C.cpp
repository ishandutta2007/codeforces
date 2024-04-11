#include <bits/stdc++.h>
#define MP make_pair
#define FF first.first
#define FS first.second
#define SF second.first
#define SS second.second
#define ALL(container) (container).begin(), (container).end()
#define FORI(i,from,to) for(int i = (from); i <= (to); i++)
#define FORD(i,from,to) for(int i = (from); i >= (to); i--)
#define REP(i,num) for(int i = 0; i < (num); i++)

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef pair<int,int> PII;
const double Eps = 1e-7;
inline bool is_zero(double x){ return (x >= -Eps) && (x <= Eps); }


struct LinearFunc {
	LL a, b; // ax + b

	LinearFunc(){}
	LinearFunc(LL a, LL b) : a(a), b(b) {}

	LL operator()(int x) const {
		return (LL)a * x + b;
	}

	LL cut(const LinearFunc L) const {
//		printf("cut (%lld,%lld) (%lld,%lld)\n", a, b, L.a, L.b);
		assert(L.a < a);
		LL val = (b-L.b) / (L.a - a) - 2;
		if(val > 2000000000)
			return 2000000000;
		if(val < -2000000000)
			return -2000000000;

//		printf("%lld\n", val);
		int cnt = 0;
		while(operator()(val) < L(val)){
//			printf("%lld or %lld\n", operator()(val), L(val));
			cnt++;
			val++;
			assert(cnt <= 5);
		}
		return val;
	}

	bool operator<(const LinearFunc L) const {
		if(a == L.a) return a < L.a; else return b < L.b;
	}
};


struct LinearHull {
	vector<pair<pair<int,int>,LinearFunc>> V;

	void insert(const LinearFunc L){
		while(!V.empty() && (V.rbegin()->second).cut(L) <= (V.rbegin()->first.first)){
			V.pop_back();
		}
		int fromWhere = 0;
		if(!V.empty()){
			fromWhere = V.rbegin()->second.cut(L);
			V.rbegin()->first.second = fromWhere-1;
		}
		V.push_back(make_pair(make_pair(fromWhere, 2000000000), L));
	}

	LL operator()(int x) const {
		auto search = make_pair(make_pair(x, 2100000000),  LinearFunc(0,0));
		auto result = *(upper_bound(V.begin(), V.end(), search)-1);
		return (result.second)(x);
	}

	void debug() const {
/*		for(int i = 0; i < V.size(); i++)
			printf("%d %d (%d,%d)\n",
					V[i].first.first, V[i].first.second,
					V[i].second.a, V[i].second.b);
	*/
	}
} LH;

const int MaxN = 100005;
int tabA[MaxN], tabB[MaxN], N;

void input(){
	scanf("%d", &N);
	for(int i = 0; i < N; i++) scanf("%d", &tabA[i]);
	for(int i = 0; i < N; i++) scanf("%d", &tabB[i]);
}




int main(){
	input();
	
	LH.insert(LinearFunc(tabB[0], tabB[0]));

	LL result = 0;
	for(int i = 1; i < N; i++){
		LL minVal = LH(tabA[i]-1);
		LH.insert(LinearFunc(tabB[i], minVal+tabB[i]));
		result = minVal;

		LH.debug();
	}
	printf("%I64d\n", result);
}