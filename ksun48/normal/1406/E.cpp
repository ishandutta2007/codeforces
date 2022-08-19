#include <bits/stdc++.h>
using namespace std;

const int TEST = 0;

int nq;

int n;
set<int> s;

int X;

void init(){
	nq = 0;
	cin >> X;
	for(int i = 1; i <= n; i++) s.insert(i);	
}

int A(int x){
	if(x > n) return 0;
	nq++;
	if(TEST){
		int ret = 0;
		for(int a : s) if(a % x == 0) ret++;
		return ret;
	} else {
		cout << "A " << x << '\n';
		cout << flush;
		cin >> x;
		return x;
	}
}
int B(int x){
	if(x > n) return 0;
	assert(x != 1);
	nq++;
	if(TEST){
		int ret = 0;
		vector<int> del;
		for(int a : s) if(a % x == 0){
			ret++;
			if(a != X) del.push_back(a);
		}
		for(int a : del) s.erase(a);
		return ret;
	} else {
		cout << "B " << x << '\n';
		cout << flush;
		cin >> x;
		return x;
	}
}
void C(int x){
	assert(1 <= x && x <= n);
	if(TEST) assert(x == X);
	cout << "C " << x << '\n';
}
int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	cin >> n;
	if(TEST){
		init();
	}
	vector<int> pr;
	for(int p = 2; p <= n; p++){
		bool is_prime = true;
		for(int q : pr){
			if(q * q > p) break;
			if(p % q == 0){
				is_prime = false;
				break;
			}
		}
		if(is_prime){
			pr.push_back(p);
		}
	}
	vector<int> big_pr;
	for(int p : pr){
		if(p * p > n){
			for(int q : pr){
				if(q >= p) big_pr.push_back(q);
			}
			break;
		}
		B(p);
	}
	int csz = A(1);
	int exp = (int)big_pr.size() + 1;
	assert(csz == exp || csz == exp + 1);

	int bpf = 1;
	int done = 0;
	while(big_pr.size()){
		vector<int> bp1, bp2;
		for(int i = 0; i < (int)big_pr.size(); i++){
			if(i % 2 == 0){
				bp1.push_back(big_pr[i]);
			} else {
				bp2.push_back(big_pr[i]);
			}
		}
		int nsz = csz;
		for(int p : bp1){
			int a = B(p);
			if(a == 2){
				bpf = p;
				break;
			} else {
				assert(a == 1);
			}
			nsz -= 1;
		}
		if(bpf > 1) break;
		csz = A(1);
		if(csz == nsz){
			big_pr = bp2;
		} else {
			assert(csz == nsz + 1);
			done = 1;
			big_pr = bp1;
			break;
		}
	}
	if(done){
		for(int p : big_pr){
			if(B(p) > 0){
				bpf = p;
			}
		}
	}
	for(int p : pr){
		while(p <= n / p && bpf <= n / p && B(bpf * p)){
			bpf *= p;
		}
	}
	if(TEST){
		cerr << bpf << '\n';
		cerr << nq << '\n';
	}
	assert(nq <= 10000);
	C(bpf);
}