#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;

vector<int> V,X[26];
string v,ans; int K,L;
string alp="abcdefghijklmnopqrstuvwxyz";

string out()
{
    int i,j,l;

    cin >> v >> K; L = v.length();
    for (i=0;i<L;i++) V.push_back(i);
    while (1){
        for (i=0;i<26;i++) X[i].clear();
        for (i=0;i<V.size();i++) X[v[V[i]]-'a'].push_back(V[i]);
        for (i=0;i<26;i++){
            if (K <= X[i].size()) return ans + alp[i];
            K -= X[i].size();
            l = 0;
            for (j=0;j<X[i].size();j++){
                l += L - X[i][j] - 1;
            }
            if (K <= l){
                ans += alp[i]; V.clear();
                for (j=0;j<X[i].size();j++){
                    if (X[i][j] < L-1) V.push_back(X[i][j]+1);
                }
                break;
            }
            K -= l;
        }
        if (i == 26) break;
    }

    return "No such line.";
}

int main()
{
    cout << out();

    return 0;
}