# include <bits/stdc++.h>
using namespace std;

vector< vector<int> >circle;

int v[100010];
int p[100010];

int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> p[i];
    }
    for(int i = 1; i <= n; ++i) if(!v[i]) {
        v[i] = true;
        vector<int> tmp(1,i);
        for(int j = p[i]; j != i; j=p[j]) {
            v[j] = true;
            tmp.push_back(j);
        }
        circle.push_back(tmp);
    }
    size_t sz = n + 1;
    auto it = circle.begin();
    for(auto i = it; i != circle.end(); ++i)
        if(i->size() < sz) {
            sz = i->size();
            it = i;
        }
    vector<int> c(*it);
    circle.erase(it);

    if(sz >= 3) { puts("NO"); return 0; }
    if(sz == 1) {
        puts("YES");
        for(auto vec:circle) {
            for(auto u:vec) {
                cout << u << ' ' << c[0] << endl;
            }
        }
    } else if(sz == 2) {
        bool flag = true;
        for(auto vec:circle) 
            if(vec.size() & 1) flag = false;
        if(flag) {
            puts("YES");
            cout << c[0] << ' ' << c[1] << endl;
            for(auto vec:circle) {
                for(size_t i = 0; i < vec.size(); i += 2) {
                    printf("%d %d\n", vec[i], c[0]);
                    printf("%d %d\n", vec[i + 1], c[1]);
                }
            }
        } else {
            puts("NO");
        }
    }
}