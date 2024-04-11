#include <iostream>
#include <utility>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
#define MP make_pair
#define PB push_back
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)

int main(){
    int n,l,k;
    cin >> n >> l >> k;
    string s;
    cin >> s;
    sort(s.begin(),s.end());
    int a = 0;
    int id = 0;
    vector<string>res(n);
    rep(i,l){
        for(int j=a;j<k;j++){
            res[j].push_back(s[id]);
            id++;
        }
        int aa = 100000;
        for(int j=a;j<k;j++){
            if(res[j][i]==res[k-1][i]){
                aa = min(aa,j);
            }
        }
        a = aa;
    }
    rep(i,n){
        while(res[i].size()<l){
            res[i].push_back(s[id]);
            id++;
        }
    }
    rep(i,n){
        cout << res[i] << "\n";
    }
    return 0;
}