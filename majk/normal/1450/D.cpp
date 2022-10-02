#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;
 
template<typename T>std::istream&operator>>(std::istream&i,vector<T>&t) {for(auto&v:t){i>>v;}return i;}

class DRatingCompression {
public:
    void solve(istream& cin, ostream& cout) {
        int T; cin >> T;
        for (int t = 0; t < T; ++t) {
            int N; cin >> N;
            vector<int> A(N), C(N, 0); cin >> A;
            for (int&a: A) --a;
            for (int i = 0; i < N; ++i) C[A[i]]++;
            int l = 0, r = N-1;
            string Ans(N, '0');
            for (int i = 0; i < N-1; ++i) {
                Ans[N-1-i] = "01"[C[i] >= 1];
                if (C[i] == 1) {
                    if (A[l] == i) ++l;
                    else if (A[r] == i) --r;
                    else break;
                } else {
                    break;
                }
            }
 
            Ans[0] = "01"[*max_element(C.begin(),C.end()) == 1];
            cout << Ans << '\n';
        }
    }
};
 
 
 
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	DRatingCompression solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	solver.solve(in, out);
    return 0;
}