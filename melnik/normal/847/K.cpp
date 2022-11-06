#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second

const int N = 3e2 + 10;

map< pair<int,int>,int> t;
int x[N], y[N];
map<string, int> f;

int get(string s){
    if(f.count(s))return f[s];
    int c=f.size();
    return f[s]=c;
}

int main() {
    int n, a, b, k, f;
    cin >> n >>a>>b>>k>>f;
    int res=0;
    for(int i = 1; i <= n; ++i) {
        string C,D;
        cin >> C >> D;
        x[i] = get(C);
        y[i] = get(D);
        int c;
        if (x[i] == y[i - 1] && i > 1) {
            c=b;
        }else c=a;
        res+=c;
        t[minmax(x[i],y[i])]+=c;
    }
    vector<int> ff;
    for(auto x:t){
        ff.push_back(max(0,x.second-f));
    }
    sort(ff.begin(), ff.end());
    reverse(ff.begin(), ff.end());
    for(int i=0;i<ff.size()&&i<k;++i)res-=ff[i];
    cout<<res<<endl;

}