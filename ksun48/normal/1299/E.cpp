#include <bits/stdc++.h>
using namespace std;

bool TEST = false;

vector<int> p;

int n;

vector<int> ans;

int ops = 0;
void init(){
	ops = 0;
	mt19937 mt_a(90000);
	p.assign(n, 0);
	for(int i = 0; i < n; i++) p[i] = i;
	shuffle(p.begin(), p.end(), mt_a);
	if(TEST){
		mt19937 mt_b(time(0));
		ans.assign(n, 0);
		for(int i = 0; i < n; i++) ans[i] = i;
		shuffle(ans.begin(), ans.end(), mt_b);
	}
}

bool ask(vector<int> z){
	ops++;
	if(TEST){
		int sum = 0;
		for(int r : z){
			sum += ans[r];
		}
		return (sum % (int)(z.size()) == 0);
	} else {
		cout << "? " << z.size();
		for(int r : z){
			cout << ' ' << 1 + p[r];
		}
		cout << '\n';
		cout << flush;
		int res;
		cin >> res;
		return (res == 1);
	}
}

void answer(vector<int> z){
	vector<int> real_ans(n);
	for(int i = 0; i < n; i++){
		real_ans[p[i]] = z[i];
	}
	if(TEST){
		cerr << "output ";
		for(int a : z){
			cerr << a << ' ';
		}
		cerr << '\n';
		cerr << "answer ";
		for(int a : ans){
			cerr << a << ' ';
		}
		cerr << '\n';
		cerr << ops << ' ' << 18 * n << '\n';
	} else {
		if(real_ans.front() >= n-1-real_ans.front()){
			for(int& x : real_ans) x = n-1-x;
		}
		cout << '!';
		for(int a : real_ans){
			cout << ' ' << a + 1;
		}
		cout << '\n';
		cout << flush;
	}
}

vector<int> find_ends(vector<int> x, int s = -1){
	if(x.size() == 2) return x;
	mt19937 mt(48);
	shuffle(x.begin(), x.end(), mt);
	assert(x.size() % 2 == 0);
	vector<int> res;
	if(s >= 0) res.push_back(s);
	for(int a : x){
		if(s == a) continue;
		vector<int> z;
		for(int b : x) if(b != a) z.push_back(b);
		if(ask(z)) res.push_back(a);
		if(res.size() == 2) break;
	}
	assert(res.size() == 2);
	return res;
}

void solve(){
	cin >> n;

	init();

	/*for(int i = 0; i < n; i++){
		cerr << ans[i] << ' ';
	}
	cerr << '\n';*/
	vector<int> output(n, -1);
	vector<vector<int> > workset(1);
	vector<int> smallest(1);

	int C = n;
	for(int i = 0; i < n; i++){
		workset[0].push_back(i);
	}
	vector<int> v = find_ends(workset[0]);
	smallest[0] = v[0];
	// cerr << smallest[0] << '\n';
	int R = 1;
	while(true){
		assert(C % (2 * R) == 0);
		int L = C / R;
		if(L == 2){
			for(int i = 0; i < R; i++){
				// cerr << smallest[i] << ' ' << workset[i][0] << ' ' << workset[i][1] << '\n';
				output[smallest[i]] = i;
				output[workset[i][0] ^ workset[i][1] ^ smallest[i]] = i + R;
			}
			break;
		}
		vector<vector<int> > ends(R);
		vector<vector<int> > ends2(R);
		for(int i = 0; i < R; i++){
			if(R == 1){
				ends[i] = v;
			} else {
				ends[i] = find_ends(workset[i], smallest[i]);
			}
			vector<int> new_workset;
			for(int a : workset[i]){
				if(a != ends[i][0] && a != ends[i][1]) new_workset.push_back(a);
			}
			ends2[i] = find_ends(new_workset);
		}
		vector<vector<int> > parity(R, vector<int>(L));

		vector<int> new_smallest(2 * R);
		vector<vector<int> > new_workset(2 * R);
		for(int i = 0; i < R; i++){
			vector<int> rest_ends;
			for(int j = 0; j < R; j++) if(j != i) for(int a : ends[j]) rest_ends.push_back(a);
			parity[i][0] = 0;
			for(int j = 1; j < L; j++){
				vector<int> qq = rest_ends;
				qq.push_back(workset[i][0]);
				qq.push_back(workset[i][j]);
				parity[i][j] = 1 ^ ask(qq);
			}
			int flip = 0;
			for(int j = 0; j < L; j++){
				if(smallest[i] == workset[i][j]){
					flip = parity[i][j];
				}
			}
			if(flip) for(int j = 0; j < L; j++) parity[i][j] ^= 1;
			/*for(int r : parity[i]) cerr << r << ' ';
			cerr << '\n';*/
			if(smallest[i] != ends[i][0]) swap(ends[i][0], ends[i][1]);
			assert(smallest[i] == ends[i][0]);

			int f1 = 0;
			int f2 = 0;
			for(int j = 0; j < L; j++){
				if(workset[i][j] == smallest[i]) f1 = parity[i][j];
				if(workset[i][j] == ends2[i][0]) f2 = parity[i][j];
			}
			if(f1 == f2) swap(ends2[i][0], ends2[i][1]);
			//cerr << ends[i][0] << ends[i][1] << ends2[i][0] << ends2[i][1] << '\n';
			new_smallest[i] = smallest[i];
			new_smallest[i + R] = ends2[i][0];
			//cerr << "ans " << ans[new_smallest[i]] << ' ' << ans[new_smallest[i + R]] << '\n';
			// 0 9 1 8
			for(int j = 0; j < L; j++){
				if(L % 4 == 2 && (workset[i][j] == ends[i][1] || workset[i][j] == ends2[i][1])){
					output[workset[i][j]] = i + (L-2 + parity[i][j]) * R;
				} else {
					new_workset[i + R * parity[i][j]].push_back(workset[i][j]);
				}
			}
		}
		smallest = new_smallest;
		workset = new_workset;
		R *= 2;
		if(C % (2 * R) != 0) C -= R;
		/*for(int a : output){
			cerr << a << ' ';
		}
		cerr << '\n';*/
	}
	answer(output);
}
int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	solve();
}