#include<bits/stdc++.h>
#define st first
#define nd second
using namespace std;
const int N = 1e5 + 10;
string str[N],ans;
int pos[20 * N];
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int n;
    cin >> n;
    int las = 0;
    for(int i = 1; i <= n; i++){
        cin >> str[i];
        int k;
        cin >> k;
        while(k--){
            int x;
            cin >> x;
            if(pos[x] == 0) pos[x] = i;
            else if(str[pos[x]].size() < str[i].size()) pos[x] = i;
            las = max(las, x  + (int)str[i].size() - 1);
        }
    }
    pair<int, int> pt = {0, -1};
    for(int i = 1; i <= las; i++){
        if(pos[i] != 0){
            if(pt.st == 0 || (int)str[pt.st].size() - pt.nd < (int)str[pos[i]].size() ){
                pt = {pos[i], 0};
            }
        }
        ans += (pt.st == 0 ? 'a' : str[pt.st][pt.nd++]);
        if(pt.nd == (int)str[pt.st].size()) pt = {0, -1};
    }
    cout << ans;
}