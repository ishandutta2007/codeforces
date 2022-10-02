#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <type_traits>

using namespace std;
#define x first
#define y second
template<typename T>class vector2:public vector<vector<T>>{public:vector2(){} vector2(size_t a,size_t b,T t=T()):vector<vector<T>>(a,vector<T>(b,t)){}};
template<typename T>class vector3:public vector<vector2<T>>{public:vector3(){} vector3(size_t a,size_t b,size_t c,T t=T()):vector<vector2<T>>(a,vector2<T>(b,c,t)){}};
template<typename T>std::ostream&operator<<(std::ostream&o,const vector<T>&t) {if(t.empty())o<<'\n';for(size_t i=0;i<t.size();++i){o<<t[i]<<" \n"[i == t.size()-1];}return o;}

typedef long long ll;
typedef unsigned int ui;

template <typename Input> struct KMP {
    explicit KMP(const Input&W) : W(W), T(W.size()+1,-1) {
        int c=0, p =1;
        while(p<W.size()) {
            if(W[p]==W[c]){T[p]=T[c];}
            else {T[p]=c;while(c>=0&&W[p]!=W[c])c=T[c];}
            ++p;++c;
        }
        T[p]=c;
    }

    vector<ui> search(const Input&S) {
        vector<ui> M;
        for (ui m=0,i=0; m+i < S.size();) {
            if (W[i] == S[m+i]) { if (i + 1 < W.size()) { ++i; continue; } else M.push_back(m); }
            m += i - T[i];
            i = ui(max(T[i],0));
        }
        return M;
    }

    template <typename Character>
    int advance(int i, Character ch) {
        while (i != -1) {
            if (i < W.size() && W[i] == ch) return i+1;
            i = T[i];
        }
        return 0;
    }

    Input W;
    vector<int> T;
};

int main() {
    string S; cin >> S;
    int N = S.size();
    int M; cin >> M;
    vector<string> T(M);
    for (string&t:T) cin >> t;
    vector3<int> D(2, M, N, 0);

    for (int w = 0; w < 2; ++w) {
        for (int i = 0; i < M; ++i) {
            KMP<string> K(T[i]);
            int p = 0;
            for (int j = 0; j < N; ++j) {
                p = K.advance(p, S[j]);
                if (p) D[w][i][j-p+1] = p;
            }
        }

        if (!w) {
            reverse(S.begin(),S.end());
            for (string&t:T) reverse(t.begin(),t.end());
        }
    }


    int ans = 0;
    for (int i = 0; i < M; ++i) {
        int m = T[i].size();
        int longest = 0;
        int cur = 0;
        if (m == 1 || m > S.size()) continue;
        for (int j = N-m; j >= 0; --j) {
            int k = N-m-j;
            int b = D[1][i][k];
            longest = max(longest, b);
            int f = D[0][i][j];
            if (f+longest >= m) {
                cur = 1;
                break;
            }
        }
        ans += cur;
    }
    cout << ans << endl;
}