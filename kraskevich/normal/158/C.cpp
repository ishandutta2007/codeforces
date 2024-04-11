#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <map>
using namespace std;

typedef map<string, int> strmap;
typedef strmap::value_type val;

struct node {
       string name;
       strmap child;
       int par;
       node(int p, string s) {
                child.clear();
                par = p;
                name = s;
       }
};

int last, cur;
vector<node> tree;

void init() {
     tree.push_back(node(-1, "/"));
     last = 1;
     cur = 0;
}

void go(string s) {
     node t = tree[cur];
     if(t.child.count(s) == 0) {
                           tree.push_back(node(cur, s));
                           t.child.insert(val(s, last++)); 
     }
     cur = t.child[s];
}

string go_back(int pos) {
      string res = "";
      while(pos != 0) {
                res = "/" + tree[pos].name + res;
                pos = tree[pos].par;
      }
      return res;
} 

int main() {
    init();
    ios_base::sync_with_stdio(0);
    
    int n;
    cin >> n;
    vector<string> ans;
    for(int nn = 0; nn < n; ++nn) {
            string cm;
            cin >> cm;
            if(cm == "pwd") 
                  ans.push_back(go_back(cur) + "/");
            else {
                 string path;
                 cin >> path;
                 int pos = 0;
                 if(path[0] == '/') {
                            cur = 0;
                            ++pos;
                 }
                 while(pos < path.length()) {
                           string t = "";
                           while(pos < path.length() && path[pos] != '/') {
                                     t += path[pos];
                                     pos++;
                           }
                           if(t == "..")
                                cur = tree[cur].par;
                           else
                               go(t);
                           ++pos;
                 }
            }
    }
    for(int i = 0; i < ans.size(); ++i)
            cout << ans[i] << endl;
    cin >> n;
    return 0;
}