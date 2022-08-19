#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

#define MAXN 1000000000
vector<int> p = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 
    53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

vector<int> vert;
vector<int> numprime(3000000, 100000);
vector<int> dist(3000000, 100000);

int l, r, steps;

void gen(int idx, int num){
    if(idx == p.size()){
        vert.push_back(num);
        return;
    }
    if(MAXN / p[idx] >= num) gen(idx, num * p[idx]);
    gen(idx + 1, num);
}

int main(){
    cin >> l >> r >> steps;
    gen(0,1);
    sort(vert.begin(), vert.end());
    //cout << vert[0] << " " << vert[1] << " " << vert[2] << endl;
    //cout << vert[vert.size()-3] << " " << vert[vert.size()-2] << " " << vert[vert.size()-1] << endl;
    numprime[0] = 0;
    dist[0] = 0;
    for(int a = 1; a <= 100; a++){
        int k = 0;
        for(int i = 0; i < vert.size(); i++){
            while(k < vert.size()){
                if(vert[k] < vert[i] * a){
                    k++;
                } else {
                    break;
                }
            }
            if(k == vert.size()) break;
            numprime[k] = min(numprime[k], numprime[i] + 1);
            dist[k] = min(dist[k], numprime[k] + a);
        }
    }
    int ans = 0;
    for(int i = 0; i < vert.size(); i++){
        if(vert[i] < l || vert[i] > r) continue;
        if(dist[i] <= steps) ans++;
    }
    cout << ans << endl;
}