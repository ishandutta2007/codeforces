//suffix tree
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 1505;

string s;
bool bad[200];
int k;
int num;
int z;
char tree[MAXN*MAXN];
vector<int> childs[MAXN*MAXN];

void maketree(int node, int ind, string s) {
    if (ind==s.length()) return;
    int index=-1;
    for (int i=0; i<childs[node].size(); i++) {
        if (tree[childs[node][i]]==s[ind]) index=i;
    }
    if (index==-1) {
        childs[node].push_back(z);
        index=childs[node].size()-1;
        tree[z]=s[ind];
        z++;
    }
    maketree(childs[node][index], ind+1, s);
}

int dfs(int node, int numk) {
    if (numk+bad[tree[node]]>k) return 0;
    int n=1;
    for (int i=0; i<childs[node].size(); i++) n+=dfs(childs[node][i], numk+bad[tree[node]]);
    return n;
}

int main() {
    //freopen("271D.in", "r", stdin);
    cin >> s;
    for (char c='a'; c<='z'; c++) {
        char b;
        cin >> b;
        bad[c]=(b=='0');
    }
    cin >> k;
    tree[z++]=' ';
    for (int i=0; i<s.length(); i++) maketree(0, 0, s.substr(i));
    cout << dfs(0, 0)-1 << endl;
}