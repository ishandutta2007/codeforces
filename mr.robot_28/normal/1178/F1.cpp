#include <iostream>
#include <vector>

using namespace std;

template <unsigned int N> class Field {
    typedef unsigned int ui;
    typedef unsigned long long ull;
public:
    inline Field(int x = 0) : v(x) {}
    inline Field<N>&operator+=(const Field<N>&o) {if (v+o.v >= N) v += o.v - N; else v += o.v; return *this; }
    inline Field<N>&operator*=(const Field<N>&o) {v=(ull)v*o.v % N; return *this; }
    inline Field<N> operator*(const Field<N>&o) const {Field<N>r{*this};return r*=o;}
	inline explicit operator ui() const { return v; }
private: ui v;
};
template<unsigned int N>ostream &operator<<(std::ostream&os,const Field<N>&f){return os<<(unsigned int)f;}
template<unsigned int N>Field<N> operator*(int i,const Field<N>&f){return Field<N>(i)*f;}

typedef Field<998244353> F;

int main() {
    ios_base::sync_with_stdio(false);
    
    int N, M; cin >> N >> M;
    vector<int> C(N); for (int &c: C) { cin >> c; --c; }
    
    vector<vector<F>> D(N+1, vector<F>(N+1, 1));
    for (int l = 1; l <= M; ++l) {
        for (int a = 0; a + l <= M; ++a) {
            pair<int,int> lo = {C[a],0};
            for (int i = 0; i < l; ++i) lo = min(lo, {C[a+i],i});
            int j = lo.second;
            if (j < 0 || j >= l) { D[a][l] = 0; continue; }
            F left = 0, right = 0;
            for (int u = 0; u <= j; ++u) left += D[a][u] * D[a+u][j-u];
            for (int v = j+1; v <= l; ++v) right += D[a+j+1][v-(j+1)] * D[a+v][l-v];
            D[a][l] = left * right;
        }
    }
    
    cout << D[0][N] << endl;
}