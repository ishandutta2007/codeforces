#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long ll;

struct House{
    int a, b, c, d;
    House(){}
    House(int x, int y, int z, int w)
        :a(x), b(y), c(z), d(w)  {}
};

ostream &operator << (ostream &os, House h){
    os << "House(" << h.a << ", " << h.b << ", " << h.c << ", " << h.d << ")";
    return os;
}

struct HOR{
    const bool operator()(const House &h1, const House &h2) const{
        return h1.a < h2.a;
    }
};

struct VER{
    const bool operator()(const House &h1, const House &h2) const{
        return h1.b < h2.b;
    }
};

bool cut(vector<House>::iterator H_begin, vector<House>::iterator H_end, bool hor){
    if (H_begin + 1 == H_end) return true;
    if (hor) stable_sort(H_begin, H_end, HOR()); else stable_sort(H_begin, H_end, VER());
    int n = H_end - H_begin;
    if (hor){
        int curend = H_begin->c;
        vector<House>::iterator prev = H_begin;
        for (int i = 1; i < n; ++i){
            if (curend <= (H_begin + i)->a){
                if (!cut(prev, H_begin + i, !hor)) return false;
                prev = H_begin + i;
            }
            curend = max(curend, (H_begin + i)->c);
        }
        if (prev == H_begin) return false;
        if (cut(prev, H_end, !hor)) return true;
    }
    if (!hor){
        int curend = H_begin->d;
        vector<House>::iterator prev = H_begin;
        for (int i = 1; i < n; ++i){
            if (curend <= (H_begin + i)->b){
                if (!cut(prev, H_begin + i, !hor)) return false;
                prev = H_begin + i;
            }
            curend = max(curend, (H_begin + i)->d);
        }
        if (prev == H_begin) return false;
        if (cut(prev, H_end, !hor)) return true;
    }
    return false;
}

int main(){
    int n;
    cin >> n;
    vector<House> H(n);
    for (int i = 0; i < n; ++i){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        H[i] = House(a, b, c, d);
    }
    bool not_a_legend = cut(H.begin(), H.end(), true) || cut(H.begin(), H.end(), false);
    cout << (not_a_legend? "YES" : "NO");
    return 0;
}