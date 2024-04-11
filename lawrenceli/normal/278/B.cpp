#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

const int MAXN = 100000;

typedef pair<int, string> pis;

int n;
vector<char> tree;
vector<int> childs[MAXN];
queue<pis> q;

void add(string s) {
    int ind=0;
    for (int i=0; i<s.length(); i++) {
        int next=-1;
        for (int j=0; j<childs[ind].size(); j++) {
            if (tree[childs[ind][j]]==s[i]) next=childs[ind][j];
        }
        if (next==-1) {
            tree.push_back(s[i]);
            childs[ind].push_back(tree.size()-1);
            next = tree.size()-1;
        }
        ind = next;
    }
}

bool comp(pis p1, pis p2) {
    return p1.second[p1.second.size()-1]<p2.second[p2.second.size()-1];
}

int main() {
    cin >> n;
    tree.push_back(' ');
    for (int i=0; i<n; i++) {
        string s;
        cin >> s;
        for (int j=0; j<s.length(); j++) add(s.substr(j));
    }
    q.push(pis(0, ""));
    while (!q.empty()) {
        int size = q.size();
        for (int i=0; i<size; i++) {
            pis p = q.front();
            q.pop();
            bool vis[200];
            vector<pis> v;
            for (char c='a'; c<='z'; c++) vis[c]=false;
            for (int j=0; j<childs[p.first].size(); j++) {
                vis[tree[childs[p.first][j]]]=true;
                v.push_back(pis(childs[p.first][j], p.second+tree[childs[p.first][j]]));
            }
            for (char c='a'; c<='z'; c++) {
                if (!vis[c]) {
                    cout << p.second+c << endl;
                    return 0;
                }
            }
            sort(v.begin(), v.end(), comp);
            for (int i=0; i<v.size(); i++) q.push(v[i]);
        }
    }
}