
#include<vector>
#include<map>
#include<iostream>

using namespace std;

int min(int a, int b, int c, int d, int e, int f){
    return min(min(min(a, b), min(c, d)), min(e, f));
}

int main(){
    const int N[6] = {4, 8, 15, 16, 23, 42};
    map<int, int> idx = {{4, 1}, {8, 2}, {15, 3}, {16, 4}, {23, 5}, {42, 6}};
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i){
        cin >> a[i];
    }
    vector<int> seqs(7);
    seqs[0] = n;
    int amount = 0;
    for (int i = 0; i < n; ++i){
        if (seqs[idx[a[i]] - 1] == 0) continue;
        --seqs[idx[a[i]] - 1];
        ++seqs[idx[a[i]]];
    }
    cout << n - seqs[6] * 6 << endl;
}