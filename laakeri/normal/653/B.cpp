#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

map<string, int> ok;

vector<pair<string, char> > op;

int can(string s){
    if (s=="a") return 1;
    if ((int)s.size()==1) return 0;
    if (ok.count(s)) return ok[s];
    int f=0;
    for (int i=0;i<1;i++){
        for (auto o:op){
            if (s[i]==o.F[0]&&s[i+1]==o.F[1]){
                string ns;
                for (int j=0;j<i;j++){
                    ns+=s[j];
                }
                ns+=o.S;
                for (int j=i+2;j<(int)s.size();j++){
                    ns+=s[j];
                }
                //cout<<s<<" "<<ns<<" "<<i<<" "<<s[i]<<" "<<s[i+1]<<" "<<o.F[0]<<" "<<o.F[1]<<endl;
                if (can(ns)){
                    f=1;
                    break;
                }
            }
        }
        if (f){
            break;
        }
    }
    ok[s]=f;
    return f;
}

int v=0;

void go(int i, int n, string s){
    if (i==n){
        if (can(s)){
            v++;
        }
        return;
    }
    for (char c='a';c<='f';c++){
        go(i+1, n, s+c);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,q;
    cin>>n>>q;
    for (int i=0;i<q;i++){
        string a;
        char b;
        cin>>a>>b;
        op.push_back({a, b});
    }
    go(0, n, "");
    cout<<v<<endl;
}