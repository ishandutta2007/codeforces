#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second

const int N = 2e5 + 10;

vector <int> ans[N];
int idx[N];

int main() {
//    ifstream cin( "input.txt" );
    int n;
    cin >> n;
    set < pair <int, int> > q;
    int cnt=0;
    for(int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        if(q.empty()||q.begin()->first>x){
            ++cnt;
            q.insert(make_pair(x, cnt));
            ans[cnt].push_back(x);
        }else{
            auto z=--q.lower_bound(make_pair(x,-1));
            ans[z->second].push_back(x);
            auto p=*z;
            q.erase(z);
            p.first=x;
            q.insert(p);
        }
    }
    for(int i=1;i<=cnt;++i){
        for(int x:ans[i])cout<<x<<' ';
        cout<<'\n';
    }
}