#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

vector<int> cycle1 = {2, 6, 10, 23, 4, 8, 12, 21, 17, 19, 20, 18};
vector<int> cycle2 = {3, 17, 10, 16, 4, 19, 9, 14, 6, 8, 7, 5};
vector<int> cycle3 = {13, 5, 17, 21, 14, 6, 18, 22, 1, 3, 4, 2};
vector<vector<int> > cycles;
int ans = 0;
void solved(vector<int> f){
    for(int j = 1; j < 24; j += 4){
        if(f[j] != f[j+1]) return;
        if(f[j] != f[j+2]) return;
        if(f[j] != f[j+3]) return;
    }
    ans = 1;
}

vector<int> apply(vector<int> cycle, vector<int> perm){
    vector<int> newperm = perm;
    for(int j = 0; j < cycle.size(); j++){
        int k = 4*(j/4) + (j+1)%4;
        newperm[cycle[j]] = perm[cycle[k]];
    }
    return newperm;
}
int main(){

    vector<int> perm;
    perm.push_back(-1);
    for(int i = 0; i < 24; i++){
        int a;
        cin >> a;
        perm.push_back(a);
    }

    solved(apply(cycle1,perm));
    solved(apply(cycle2,perm));
    solved(apply(cycle3,perm));
    solved(apply(cycle1,apply(cycle1,apply(cycle1,perm))));
    solved(apply(cycle2,apply(cycle2,apply(cycle2,perm))));
    solved(apply(cycle3,apply(cycle3,apply(cycle3,perm))));

    if(ans){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}