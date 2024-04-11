#include <vector>
#include <algorithm>
#include <numeric>
#include <iostream>
using namespace std;
 
template<typename T>std::istream&operator>>(std::istream&i,vector<T>&t) {for(auto&v:t){i>>v;}return i;}

class FTheStrugglingContestant {
public:
    void solve(istream& cin, ostream& cout) {
        int T; cin >> T;
        for (int t = 0; t < T; ++t) {
            int N; cin >> N;
            vector<int> A(N), C(N+1, 0), G(N+1, 0); cin >> A;
            for (int i = 0; i < N; ++i) {
                C[A[i]] += (i == 0 || A[i-1] == A[i]);
                C[A[i]] += (i == N-1 || A[i] == A[i+1]);
                G[A[i]]++;
            }
            int maxG = *max_element(G.begin(),G.end());
            int totC = accumulate(C.begin(),C.end(),0);
            int maxC = *max_element(C.begin(),C.end());
            cout << (2*maxG-1 > N ? -1 : max({maxC-2, totC/2-1})) << '\n';
        }
    }
};
 
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	FTheStrugglingContestant solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	solver.solve(in, out);
    return 0;
}