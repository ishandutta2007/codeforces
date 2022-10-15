#include<vector>
#include<iostream>
#include<cmath>

using namespace std;

int sort(vector<int> v){
    bool sorted = true;
    for (int i = 1; i < v.size(); ++i) {
        if (v[i - 1] > v[i]) sorted = false;
    }
    if (sorted) return v.size();
    vector<int>Left(v.size() / 2, 0);
    for (int i = 0; i < Left.size(); ++i){
        Left[i] = v[i];
    }
    vector<int>Right(v.size() / 2, 0);
    for (int i = 0; i < Right.size(); ++i){
        Right[i] = v[i + Left.size()];
    }
    return max(sort(Left), sort(Right));
}

int main(){
    int n;
    cin >> n;
    vector<int> a(n, 0);
    for (int i = 0; i < n; ++i){ cin >> a[i];}
    cout << sort(a) << endl;
    return 0;
}